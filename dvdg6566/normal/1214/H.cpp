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
#define MAXN 210000
#define MAXL 18

int N,K,a,b,L;
vi V[MAXN];

int A[MAXN];
int P[MAXN];
vi diam;
int out[MAXN];
int depth[MAXN];
int dir[MAXN];

void dfs(int x, int p){
  for (auto v :V[x])if(v!=p){
    A[v] = A[x] + 1;
    P[v] = x;
    dfs(v,x);
  }
}

int dfs2(int x, int p){
  vi tmp;
  for (auto v : V[x])if(out[v]==-1 && v!=p){
    int t = dfs2(v,x) + 1;
    depth[x] = max(depth[x], t);
    tmp.pb(t);
  }
  sort(ALL(tmp));reverse(ALL(tmp));
  if (SZ(tmp) > 1 && tmp[0] + tmp[1] + 1 >= K){
    cout<<"No";
    exit(0);
  }
  return depth[x];
}

void dfs4(int x, int p){
  for (auto v : V[x])if(v!=p){
    out[v] = 3-out[x];
    dfs4(v,x);
  }
}

int main(){
  cin>>N>>K;  

  
  for (int i=1;i<N;++i){
    cin>>a>>b;V[a].pb(b);V[b].pb(a);
  }

  if (K == 2){
    cout<<"Yes\n";
    out[1] = 1;
    dfs4(1,-1);
    for (int i=1;i<=N;++i)cout<<out[i]<<' ';
    exit(0);
  }

  dfs(1,-1);
  int cw = -1;
  int best = -1;
  for (int i=1;i<=N;++i)if(A[i] > cw){
    cw = A[i];
    best = i;
  }

  memset(A,0,sizeof(A));
  dfs(best,-1);
  int c2 = -1;
  int b2 = -1;
  for (int i=1;i<=N;++i)if(A[i] > c2){
    c2 = A[i];
    b2 = i;
  }

  int t = b2;
  while (t != best){
    diam.pb(t);
    t = P[t];
  }
  memset(out,-1,sizeof(out));
  diam.pb(best);
  int L = SZ(diam);

  if (K > L){
    cout<<"Yes\n";
    for (int i=1;i<=N;++i)cout<<1<<' ';
    exit(0);
  }

  for (int i=0;i<L;++i){
    out[diam[i]] = i%K;
  }
  for (auto i : diam)dfs2(i,-1);
  queue<int> q;

  for (int i=0;i<L;++i){
    int low = min(i, L-1-i);
    int x = depth[diam[i]];
    x = x + low + 1;
    if (depth[diam[i]] == 0)continue;
    if (x >= K){
      cout<<"No";
      exit(0);
    }
    q.push(diam[i]);
  }

  for (int i=0;i<SZ(diam)/2;++i)dir[diam[i]] = -1;

  while(SZ(q)){
    int x = q.front();q.pop();
    for (auto v : V[x])if(out[v] == -1){
      dir[v] = dir[x];
      if (dir[x] == -1){
        out[v] = (out[x] + K - 1)%K;
      }else {
        out[v] = (out[x] + 1) %K;
      }
      q.push(v);
    }
  }
  cout<<"Yes\n";
  for (int i=1;i<=N;++i)assert(out[i]+1 > 0 && out[i]+1 <= K);
  for (int i=1;i<=N;++i)cout<<out[i]+1<<' ';
}