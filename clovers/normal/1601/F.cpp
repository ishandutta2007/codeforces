#include<bits/stdc++.h>
typedef long long ll;
ll n, count;
const ll mod = 998244353;
const int M = 1e9 + 7;
ll power[15] = {1};
inline ll div(ll x) {
	if(x >= 0)
		return x / mod;
	else
		return - ((-x + mod - 1) / mod);
}
inline ll start_with(ll x) {
	ll sum = 0;
	for(int add = 0;add <= 12;++add) {
		if(x * power[add] > n)
			break;
		sum += std::min(power[add], n - x * power[add] + 1);
	}
	return sum;
}
inline ll bit(ll x) {
	int len = 1;
	for(;x > 9;) x /= 10, len += 1;
	return len;
}
inline ll rank(ll x) {
	int b = bit(x);
	ll r = 1;
	for(int lcp = 0;lcp < b;++lcp) {
		ll pre = x / power[b - lcp], z = x / power[b - lcp - 1] % 10;
		for(int j = !lcp;j < z;++j) {
			r += start_with(pre * 10 + j);
		}
	}
	return r + b - 1;
}
inline void dfs0(ll pre, int len) {
	const ll min = pre * power[len];
	const ll max = (pre + 1) * power[len] - 1;
	if(min > n)
		return ;
	if(max <= n) {
		const ll rmin = rank(min);
		const ll rmax = rank(max);
		if(div(rmin - max) == div(rmax - min)) {
			count -= div(rmin - max) * power[len];
			count %= M;
			return ;
		}
	}
	for(int i = 0;i <= 9;++i) {
		dfs0(pre * 10 + i, len - 1);
	}
}
int main() {
	std::cin >> n;
	for(int i = 1;i < 15;++i) power[i] = power[i - 1] * 10;

	for(int o = 0;o <= 12;++o) {
		for(int i = 1;i <= 9;++i) {
			dfs0(i, o);
		}
	}
	std::cout << (count * mod % M + M) % M << '\n';
}
/*
 98765432101
917423543
*/