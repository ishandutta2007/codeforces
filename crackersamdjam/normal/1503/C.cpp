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
const int MM = 1e5+5;

int n;
pair<int, int> a[MM];
ll dp[MM];
ll bit[MM];
ll ans;

void up(int i, ll x){
	for(i++; i < MM; i += i&-i)
		bit[i] = min(bit[i], x);
}
ll qu(int i){
	ll x = 1e15;
	for(i++; i; i -= i&-i)
		x = min(x, bit[i]);
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(bit, 0x3f, sizeof bit);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i].first>>a[i].second;
		ans += a[i].second;
	}
	sort(a, a+n);
	a[n] = {INT_MAX, 0};
	for(int i = n-2; i >= 0; i--){
		auto l = upper_bound(a, a+n+1, make_pair(a[i].first+a[i].second+1, -1));
		if(l->first == INT_MAX)
			dp[i] = 0;
		else
			dp[i] = dp[l-a] + l->first - (a[i].first+a[i].second);
		dp[i] = min(dp[i], qu(l-a-1));
		up(i, dp[i]);
		// pr(a[i].first, a[i].second, dp[i], l-a);
	}
	cout<<dp[0]+ans<<'\n';
}