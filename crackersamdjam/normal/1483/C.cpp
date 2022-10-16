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
const int MM = 3e5+5;

int n, h[MM], v[MM];
ll dp[MM], ls[MM];
int l[MM], r[MM];
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	stk.push(0);
	for(int i = 1; i <= n; i++){
		cin>>h[i];
		while(h[stk.top()] > h[i])
			stk.pop();
		l[i] = stk.top();
		stk.push(i);
	}
	stk.push(n+1);
	for(int i = n; i; i--){
		while(h[stk.top()] > h[i])
			stk.pop();
		r[i] = stk.top();
		stk.push(i);
	}

	memset(dp, -0x3f, sizeof dp);
	memset(ls, -0x3f, sizeof ls);
	dp[0] = 0;

	for(int i = 1; i <= n; i++){
		cin>>v[i];
		dp[i] = max(dp[i], dp[i-1]+v[i]);
		dp[i] = max(dp[i], ls[i]+v[i]);
		if(l[i])
			dp[i] = max(dp[i], dp[l[i]]);
		ls[r[i]] = max(ls[r[i]], ls[i]);
		ls[r[i]] = max(ls[r[i]], dp[i-1]);
		// pr(i, dp[i], ls[i], l[i], r[i]);
	}

	cout<<dp[n]<<'\n';
}