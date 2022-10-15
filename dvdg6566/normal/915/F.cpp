#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 1001000
#define MAXL 18
 
vi V[MAXN];
int val[MAXN];
int t;
vpi query;
int pre[MAXN], post[MAXN], p[MAXN];
int sub[MAXN];
int N,a,b;
int cur=0;
int invpre[MAXN];
 
int dfs(int x, int par){
  p[x]=par;
  pre[x] = t++;
  invpre[pre[x]] = x;
  sub[x]=1;
  for (auto v : V[x])if (v != par){
    sub[x] += dfs(v,x);
  }
  post[x]=t-1;
  return sub[x];
}
 
ll c2(ll x){
  return (x*(x-1))/2;
}
 
struct node{
  int v;
  node *l, *r;
  node(int s,int e){
    int m=(s+e)/2;v=1;
    if (s != e){
      l=new node(s,m);
      r=new node(m+1,e);
    }
  }
  void up(int s, int e, int x, int y, int val){
    int m=(s+e)/2;
    if (s==x&&e==y){
      v=max(v,val);
      return;
    }
    if (y <= m)l->up(s,m,x,y,val);
    else if (x>m)r->up(m+1,e,x,y,val);
    else {l->up(s,m,x,m,val); r->up(m+1,e,m+1,y,val);}
  }
  int query(int s, int e, int x){
    int m=(s+e)/2;
    if (s==e)return v;
    if (x > m)return max(v,r->query(m+1,e,x));
    else return max(v,l->query(s,m,x));
  }
}*root;
 
int f[MAXN];
void fwupdate(int x, int v) {
  for (; x<=N; x+=x&(-x)) f[x] += v;
}
int fwsum(int x) {
  int res = 0;
  for(; x; x-=x&(-x)) res += f[x];
  return res;
}
int fwquery(int a, int b){
  return fwsum(b)-fwsum(a-1);
}
 
int subtreesize(int x){
  return sub[x] - fwquery(pre[x],post[x]);
}
 
ll solve(){
  ll ans=0;
  for (auto i : query){
    int x=i.s;
    // cout<<"At "<<x<<" root query "<<root->query(pre[x])<<'\n';
    int par = invpre[root->query(1,N,pre[x])];
    int parsize = subtreesize(par);
    int subsize = subtreesize(x);
    ll rep = c2(parsize)-c2(parsize-subsize);
    // cout<<"Node "<<x<<' '<<par<<'\n';
 
    for (auto v : V[x])if (v!=p[x]){
      rep -= c2(subtreesize(v));
    }
 
    // cout<<"Subtree sizes "<<subsize<<' '<<parsize<<'\n';
 
    ans += rep*(ll)i.f;
    // cout<<rep<<' '<<i.f<<'\n';
 
    fwupdate(pre[x],subsize);
    if (par != 1)fwupdate(pre[p[par]],-subsize);
 
    for(auto v : V[x])if (v!=p[x]){
      root->up(1,N,pre[v], post[v], pre[v]); // Store the actual index
    }
  }
  return ans;
}
 
inline int readInt() {
  int x = 0;
  char ch = _getchar_nolock();
  while (ch < '0' || ch > '9') ch = _getchar_nolock();
  while (ch >= '0' && ch <= '9'){
  x = (x << 3) + (x << 1) + ch - '0';
  ch = _getchar_nolock();
  }
  return x;
}
 
int main(){
  // freopen("in.txt","r",stdin);
  N = readInt();
  cur=1;
  for (int i=1;i<=N;++i){
    val[i] = readInt();
    query.pb(mp(val[i],i));
  }
  sort(ALL(query));
  reverse(ALL(query));
  for (int i=1;i<N;++i){
    a = readInt();
    b = readInt();
    V[a].pb(b);
    V[b].pb(a);
  }
  t=1;
  dfs(1,0);
  root = new node(1,N);
  ll ans=0;
 
  ans += solve();
  root = new node(1,N);
  memset(f,0,sizeof(f));
  reverse(ALL(query));
  ans -= solve();
  cout<<ans<<' ';
}