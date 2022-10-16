#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 62;

int t, n;
ll k, dp[69];
ll sum;

int main(){
	dp[0] = 1;
	sum = 1;
	for(int i = 1; i < MM; i++){
		dp[i] = sum;
		sum += dp[i];
	}
	// for(int i = 0; i < MM; i++)
		// dp[i]--;
	// pr(dp[0], dp[1], dp[2], dp[3]);	

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		cin>>n>>k;
		// k--;
		if(n < MM and k > dp[n]){
			cout<<"-1\n";
			continue;
		}
		int cur = n;
		while(cur){
			// pr("cur", cur, k);
			for(int i = cur-1; i >= 0; i--){
				if(i >= MM or k <= dp[i]){
					for(int j = i+1; j <= cur; j++)
						cout<<n+1-j<<' ';
					cur = i;
					break;
				}
				// pr("sub", dp[i]);
				k -= dp[i];
			}
		}
		// pr("__________");
		cout<<'\n';
	}
}