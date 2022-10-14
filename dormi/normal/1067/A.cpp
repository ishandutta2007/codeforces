#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair <lli, lli> pll;

void sc() {}

template<typename T, typename... Args>
void sc(T &a, Args &... args) { cin >> a, sc(args...); }

template<typename T>
void pr(T a) { cout << a; }

template<typename T, typename... Args>
void pr(T a, Args... args) { cout << a << " ", pr(args...); }

const int MAXN=1e5+1;
lli mod=998244353;
lli make(lli a){
	while(a<0)a+=mod;
	return a%mod;
}
int arr[MAXN];
lli dp[MAXN][2][201];
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	sc(n);
	dp[0][0][0]=1;
	for(int i=1;i<=200;i++)dp[0][0][i]=(dp[0][0][i]+dp[0][0][i-1])%mod;
	for(int i=1;i<=n;i++){
		sc(arr[i]);
		if(arr[i]!=-1){
			dp[i][0][arr[i]]=(dp[i-1][1][arr[i]-1]+dp[i-1][0][arr[i]-1])%mod;
			dp[i][1][arr[i]]=make(dp[i-1][1][200]-dp[i-1][1][arr[i]-1]+dp[i-1][0][arr[i]]-dp[i-1][0][arr[i]-1]);
		}
		else{
			for(int j=1;j<=200;j++){
				dp[i][0][j]=(dp[i-1][1][j-1]+dp[i-1][0][j-1])%mod;
				dp[i][1][j]=make(dp[i-1][1][200]-dp[i-1][1][j-1]+dp[i-1][0][j]-dp[i-1][0][j-1]);
			}
		}
		for(int j=1;j<=200;j++)dp[i][0][j]=(dp[i][0][j]+dp[i][0][j-1])%mod,dp[i][1][j]=(dp[i][1][j]+dp[i][1][j-1])%mod;
	}
	pr(dp[n][1][200]);
	return 0;
}