#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const ll mod = 998244353;
const int MM = 2e5+5;

int n;
array<ll, 3> a[MM];
priority_queue<pair<ll, ll>> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	sort(a, a+n, [](auto x, auto y){
		return x[0] > y[0];
	});

	ll ans = a[0][0]+1;
	ll cur = 0;

	for(int i = 0; i < n; i++){
		auto [x, y, s] = a[i];
		while(size(q) and q.top().first >= x){
			cur += q.top().second;
			cur %= mod;
			q.pop();
		}
		ll k = (cur+s)%mod;
		// pr(i, x, y, s, cur, k);
		// how many repeats
		ans += k*(x-y)%mod;
		ans %= mod;

		cur += k;
		q.emplace(y, -k);
	}

	ans %= mod;
	if(ans < 0) ans += mod;
	cout<<ans<<'\n';
}