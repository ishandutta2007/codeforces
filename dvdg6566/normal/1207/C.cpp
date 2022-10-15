#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
ll INF = 1e15;

ll dp[201010][2];
ll T,N,A,B;
string S;

int main(){
  cin>>T;
  while(T--){
    cin>>N>>A>>B;
    cin>>S;
    S += '0';
    S += '0';
    for (int i=0;i<=N;++i)dp[i][0] = dp[i][1] = INF;
    dp[0][0] = B;
    for (int i=1;i<=N;++i){
      if (S[i-1] == '0' && S[i] == '0'){
        dp[i][0] = min(dp[i-1][0] + A + B, dp[i-1][1] + 2 * A + B);
      } 
      dp[i][1] = min(dp[i-1][0] + 2*A+2*B, dp[i-1][1] + A+2*B);
      // cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    }
    cout<<dp[N][0]<<'\n';
  }
}