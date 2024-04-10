#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=1e9+7;
const int N=2e5+5;
int n, m;

int dp[N];

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<N; i++){
		dp[i]=(dp[i-1]+dp[i-2])%MOD;
	}
	cout<<(2*(dp[n]+dp[m]-1))%MOD;
	return 0;
}