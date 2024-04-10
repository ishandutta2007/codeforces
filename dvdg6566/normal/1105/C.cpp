#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int, pi> pii;
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
#define INF 10000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

ll dp[200100][3];
ll cnt[3];
ll N,l,r;

int main(){
  cin>>N>>l>>r;
  if (r < l){
    cout<<0;
    return 0;
  }
  --l;
  for (int i=0;i<3;++i){
    cnt[i] += (r-i+3)/3;
    cnt[i] -= ((l-i+3)/3);
  }
  // cout<<'\n';
  dp[0][0] = 1;
  for (int i=1;i<=N;++i){
    dp[i][0] = ((dp[i-1][0] * cnt[0]) % MOD + (dp[i-1][1] * cnt[2]) % MOD + (dp[i-1][2] * cnt[1]) % MOD) %MOD;
    dp[i][1] = ((dp[i-1][0] * cnt[1]) % MOD + (dp[i-1][1] * cnt[0]) % MOD + (dp[i-1][2] * cnt[2]) % MOD) %MOD;
    dp[i][2] = ((dp[i-1][0] * cnt[2]) % MOD + (dp[i-1][1] * cnt[1]) % MOD + (dp[i-1][2] * cnt[0]) % MOD) %MOD;
    // cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<'\n';
  }
  cout<<dp[N][0];
}