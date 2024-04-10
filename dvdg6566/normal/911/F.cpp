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
#define MAXN 201000
#define MAXL 18

int A[MAXN], B[MAXN];
int p[MAXN];
vi V[MAXN];
int N,a,b;
int blk[MAXN];
int out[MAXN];
vector<pair<pi,int>> O;

void dfs(int x){
  for (auto v : V[x])if(A[v] == -1){
    A[v] = A[x] + 1;
    dfs(v);
  }
}

void dfs2(int x){
  for (auto v : V[x])if(B[v] == -1){
    B[v] = B[x] + 1;
    p[v] = x;
    dfs2(v);
  }
}

int best = -1;
int lw = -1;


void dfs3(int x, int par){
  for (auto v : V[x])if(par != v){
    dfs3(v,x);
  }
  if (blk[x] == 0)O.pb(mp(x,out[x]),x);
}

void dfs4(int x, int par){
  if(blk[x] == 0)return;
  for (auto v : V[x])if(par != v){
    dfs4(v,x);
  }
  O.pb(mp(x,best),x);
}

int main(){
  cin>>N;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    V[a].pb(b);
    V[b].pb(a);
  }
  memset(A,-1,sizeof(A));
  A[1] = 0;
  dfs(1);

  for (int i=1;i<=N;++i)if(A[i] > lw){
    lw = A[i];
    best=i;
  }

  memset(A,-1,sizeof(A));
  A[best] = 0;
  dfs(best);

  int best2 = -1;
  int lw2 = -1;
  for (int i=1;i<=N;++i)if(A[i] > lw2){
    lw2 = A[i];
    best2=i;
  }

  memset(B,-1,sizeof(B));
  B[best2] = 0;
  dfs2(best2);

  int t = best;
  while (t != best2){
    blk[t] = 1;
    t = p[t];
  }
  blk[best2] = 1;
  ll ans = 0;

  for (int i=1;i<=N;++i)if(!blk[i]){
    ans += max(A[i], B[i]);
    if (A[i] > B[i]){
      out[i] = best;
    }else {
      out[i] = best2;
    }
  }

  ll len = A[best2];
  ans += len*(len+1)/2;
  cout<<ans<<'\n';

  dfs3(best,-1);
  dfs4(best,-1);

  O.pop_back();

  for (auto i : O){
    cout<<i.f.f<<' '<<i.f.s<<' '<<i.s<<'\n';
  }
}