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

vi adjList[2001];
int N,a,d[2001];

void dfs(int x){
  for (auto i : adjList[x]){
    d[i] = d[x] + 1;
    dfs(i);
  }  
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin >> N;
  for (int i = 1; i <=N; ++i){
    cin >> a;
    if(a != -1)adjList[a].pb(i);
    else d[i] = 1;
  }
  for (int i =1;i<=N; ++i){
    if(d[i] == 1)dfs(i);
  }
  cout << *max_element(d,d+N+1);
}