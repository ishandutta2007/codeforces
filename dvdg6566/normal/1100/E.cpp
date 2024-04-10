#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<pi, pi> pii;
typedef set<int> si;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000002
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

vi adjList[100100];
vector<pii> edges;
int cnt;
int topoorder[100100];
bool visited[100100];
vi topo;
int N,E,a,b,w;

void dfs(int x){
  for (auto i : adjList[x]){ 
    if (visited[i])continue;
    visited[i] = 1;
    dfs(i);
  }
  topo.pb(x);
}

bool works(int x){
  for (int i=1;i<=N;++i){visited[i] = 0; adjList[i].clear();}
  while(topo.size())topo.pop_back();
  for (auto i : edges){
    if (i.f.f <= x)break;
    adjList[i.s.f].pb(i.s.s);
  }
  for (int i=1;i<=N;++i){
    if (visited[i])continue;
    visited[i] = 1;
    dfs(i);
  }
  reverse(ALL(topo));
  for (int i=0;i<N;++i)topoorder[topo[i]] = i;
  for (auto i : edges){
    if (i.f.f <= x)break;
    if (topoorder[i.s.f] > topoorder[i.s.s]){
      return 0;
    }
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> E;
  for (int i=1;i<=E;++i){
    cin>>a>>b>>w;
    edges.pb(mp(mp(w,i),mp(a,b)));
  }
  sort(ALL(edges));
  reverse(ALL(edges));
  int low = 0;
  int upp = INF;
  while (upp > low+1){
    int mid = (upp+low)/2;
    if (works(mid))upp = mid;
    else low = mid;
  }
  int ans = low;
  if (!works(low))ans = upp;
  vi res;
  works(upp);
  reverse(ALL(edges));
  for (auto i : edges){
    if (i.f.f > ans)break;
    if (topoorder[i.s.f] > topoorder[i.s.s]){
      res.pb(i.f.s);
    }
  }
  sort(ALL(res));
  cout << ans << ' ' << SZ(res) << '\n';
  for (auto i : res)cout << i << ' ';
}