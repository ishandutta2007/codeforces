#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<ll> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define MOD 1e9+7
#define lb lower_bound
#define ub upper_bound
#define dst distancer
#define INF 1000000000

vi adjList[300100];
bool used[300100];
ll val[300100],dpMEM[300100],gud[300100];
ll p[300100],N,ans,a,b,rep;

void dfs(int x){
  for (auto i : adjList[x]){
    if (p[i] != -1)continue;
    p[i] = x;
    dfs(i);
  }
}

ll dp(int x){
  if (adjList[x].size() == 1 && x!=1){
    return dpMEM[x] = val[x];
  }
  ll r = val[x];
  for (auto i : adjList[x]){
    if(i == p[x]){used[i] = 0; continue;}
    ll t = dp(i);
    r = r + max(0LL,t);
    if (t > 0LL)used[i] = 1;
    else used[i] = 0;
  }
  return dpMEM[x] = r;
}

ll dp2(int x){
  if (adjList[x].size() == 1 && x!=1){
    if(val[x] == ans){
      ++rep;
      return dpMEM[x] = -INF;

    }
    return dpMEM[x] = val[x];
  }
  ll r = val[x];
  for (auto i : adjList[x]){
    if(i == p[x]){used[i] = 0; continue;}
    ll t = dp2(i);
    r = r + max(0LL,t);
    if (t > 0LL)used[i] = 1;
    else used[i] = 0;
  }
  if (r == ans){++rep;return dpMEM[x] = -INF;}
  return dpMEM[x] = r;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i)cin >> val[i];
  for (int i = 0; i < N-1; ++i){
    cin >> a >> b;
    adjList[a].pb(b);
    adjList[b].pb(a);
  }
  memset(p,-1,sizeof(p));
  p[1] = 0;
  dfs(1);
  dp(1);
  ans = *max_element(dpMEM+1, dpMEM+N+1);
 for (int i = 1; i <= N; ++i){
    if(dpMEM[i] == ans)gud[i] = 1;
    dpMEM[i] = 0;
 }
  dp2(1);
  cout << ans*rep << ' ' << rep;
}