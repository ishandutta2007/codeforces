#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e16;
const ll MAXN = 301000;

ll A[MAXN][4];
ll dp[MAXN][4];
ll N;

int main(){
  cin>>N;
  for (int i=1;i<=N;++i)cin>>A[i][1];
  for (int i=1;i<=N;++i)cin>>A[i][2];
  for (int i=1;i<=N;++i)cin>>A[i][3];
  for (int i=1;i<=N+1;++i)for (int j=1;j<=3;++j)dp[i][j] = -INF;

  dp[1][1] = 0;
  for (int i=1;i<=N;++i){
    // cout<<A[i][1]<<' '<<A[i][2]<<' '<<A[i][3]<<'\n';
    dp[i+1][1] = max(dp[i+1][1], dp[i][1] + A[i][1]);
    dp[i+1][2] = max(dp[i+1][2], dp[i][2] + A[i][2]);
    dp[i+1][3] = max(dp[i+1][3], dp[i][3] + A[i][3]);

    dp[i+1][2] = max(dp[i+1][2], dp[i][1] + A[i][1] + A[i][2]);
    dp[i+1][2] = max(dp[i+1][2], dp[i][3] + A[i][3] + A[i][2]);
    dp[i+1][3] = max(dp[i+1][3], dp[i][2] + A[i][3] + A[i][2]);
    dp[i+1][1] = max(dp[i+1][1], dp[i][2] + A[i][1] + A[i][2]);

    dp[i+1][3] = max(dp[i+1][3], dp[i][1] + A[i][1] + A[i][2] + A[i][3]);
    dp[i+1][1] = max(dp[i+1][1], dp[i][3] + A[i][1] + A[i][2] + A[i][3]);

    dp[i+2][1] = max(dp[i+2][1], dp[i][3] + A[i][1] + A[i][2] + A[i][3] + A[i+1][1] + A[i+1][2] + A[i+1][3]);
    dp[i+2][3] = max(dp[i+2][3], dp[i][1] + A[i][1] + A[i][2] + A[i][3] + A[i+1][1] + A[i+1][2] + A[i+1][3]);
  }
  // for (int i=1;i<=N+1;++i){
  //   cout<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<'\n';
  // }
  cout<<dp[N+1][3];
}