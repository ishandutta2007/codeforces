#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distance
#define INF 1000000000

vi adjList[200100];
int pre[200100],ind[200100],O[200100];
int N,Q,a,b,c;

void dfs(int x){
  ind[x] = ++c;
  for (auto i : adjList[x]){
    dfs(i);
  }
  pre[x] = c;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N >> Q; 
  for (int i = 2; i <= N; ++i){
    cin >> a;
    adjList[a].pb(i);
  }
  dfs(1);
  for(int i =1;i<=N;++i){
    O[ind[i]] = i;
  }                           
  // for (int i = 1; i <= N; ++i)cout << O[i] << ' ';cout << '\n';
  for (int i =0;i<Q;++i){
    cin >> a >> b;
    if (ind[a] + b - 1 > pre[a])cout << "-1\n";
    else cout << O[ind[a] + b - 1] << '\n';
  }
    
   
  // for (int i = 1; i <= N; ++i)cout << i << ' ' << ind[i] << ' ' << pre[i] << '\n';
}