#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 101000
#define MAXL 18

pi better(pi a, pi b){
  if (a.f > b.f)return a;
  return b;
}

int A[MAXN], P[MAXN];
int N,a,b;
vi V[MAXN];
int pre[MAXN], post[MAXN];
int c;
int D[MAXN];

struct node{
  int s,e,m,offset;
  node *l,*r;
  pi v;
  node(int _s, int _e):s(_s),e(_e){
    m=(s+e)/2;
    offset=0;
    if (s != e){
      l = new node(s,m);
      r = new node(m+1,e);
      v = better(l->query(s,m), r->query(m+1,e));
    }else{
      v = mp(D[s], s);
    }
  }

  void prop(){
    if (offset == 0)return;
    l->offset += offset;
    r->offset += offset;
    v.f -= offset;
    offset = 0;
  }

  pi query(int x, int y){
    if (s == x && e == y){
      // cout<<"Query "<<s<<' '<<e<<' '<<v.f+offset<<'\n';
      return mp(v.f+offset, v.s);
    }
    if (y <= m)return l->query(x,y);
    else if (x > m)return r->query(x,y);
    return better(l->query(x,m), r->query(m+1,y));
  }

  void update (int x, int y, int val){
    if (s == x && e == y){
      offset+=val;
      return;
    }
    if (y <= m)l->update(x,y,val);
    else if (x > m)r->update(x,y,val);
    else l->update(x,m,val), r->update(m+1,y,val);
    v = better(l->query(s,m), r->query(m+1,e));
    // cout<<"Value "<<s<<' '<<e<<' '<<v.f<<' '<<v.s<<'\n';
  }
}*root;

int invpre[MAXN];
int blk[MAXN];

void dfs(int x, int par){
  P[x] = par;
  pre[x] = ++c;
  for (auto v : V[x])if(v!=par){
    A[v] = A[x] + 1;
    dfs(v,x);
  }
  post[x] = c;
}

int main(){
  cin >> N;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    V[a].pb(b);
    V[b].pb(a);
  }
  dfs(1,-1);
  int best = -1;
  int cw = -1;
  for (int i=1;i<=N;++i)if (cw < A[i]){
    cw = A[i];
    best = i;
  }

  blk[best] = 1;
  c=0;
  memset(A,0,sizeof(A));
  dfs(best,-1);
  
  int ans = 1;

  for (int i=1;i<=N;++i)D[pre[i]] = A[i];
  for (int i=1;i<=N;++i)invpre[pre[i]] = i;
  int L=N-1;
  cout<<1<<' ';
  root = new node(1,N);
  // for (int i=1;i<=N;++i)cout<<i<<' '<<"pre "<<pre[i]<<' '<<"post "<<post[i]<<'\n';

  while(ans<N){
    --L;
    pi cur = root -> query(1,N);
    ans += cur.f;
    // cout<<"Optimal "<<cur.s<<' '<<"dst "<<cur.f<<'\n';
    if (cur.f == 0)break;
    int x = invpre[cur.s];
    for (int i=cur.f;i>0;--i){
      blk[x] = 1;
      root->update(pre[x], pre[x], -MAXN);
      // cout<<"Removing "<<pre[x]<<'\n';
      for (auto v : V[x])if (!blk[v] && v != P[x] ){
        root->update(pre[v], post[v], -i);
        // cout<<"Update "<<pre[v]<<' '<<post[v]<<' '<<-i<<'\n';
      }
      x = P[x];
    }
    cout<<ans<<' ';
  }
  while(L--)cout<<N<<' ';
}