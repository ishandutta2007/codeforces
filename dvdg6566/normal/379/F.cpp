#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 100000000000000000;
#define SZ(x) x.size()
#define Aint(x) x.begin(),x.end()
const int MAXN = 1001000;

int N,Q,a;
vi adjList[MAXN];
int p[MAXN][20];
int depth[MAXN];

void dfs(int x){
  for (auto i : adjList[x]){
    p[i][0] = x;
    depth[i] = depth[x] + 1;
    dfs(i);
  }
}

int lca(int a, int b){
  if (a == b)return a;
  if (depth[a] < depth[b])swap(a,b);
  int h = depth[a] - depth[b];
  for (int i=0;i<20;++i)if (h&(1<<i))a = p[a][i];
  if (a == b)return a;
  for (int i=19;i>=0;--i){
    if (p[a][i] == p[b][i])continue;
    a = p[a][i];b=p[b][i];
  }
  return p[a][0];
}

int dist(int a, int b){
  return depth[a] + depth[b] - depth[lca(a,b)]*2;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>Q;
  adjList[1].pb(2);
  adjList[1].pb(3);
  adjList[1].pb(4);
  for (N=5;Q>=0;--Q,N+=2){
    cin>>a;
    adjList[a].pb(N);
    adjList[a].pb(N+1);
  }
  N -= 3;
  dfs(1);
  for (int i=1;i<20;++i){
    for (int j=2;j<=N;++j){
      if (p[j][i-1]!=-1)p[j][i] = p[p[j][i-1]][i-1];
    }
  }
  int diam1 = 2, diam2 = 3;
  int diaml = 2;
  for (int i=5;i<=N;i+=2){
    int a = dist(diam1, i);
    int b = dist(diam2, i);
    cout<<max({a,b,diaml})<<'\n';
    if (diaml >= max(a,b))continue;
    if (a >= b){
      diam2 = i;
      diaml = a;
    }else{
      diam1 = i;
      diaml = b;
    }
  }
}