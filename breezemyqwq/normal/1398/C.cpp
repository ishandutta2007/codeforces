#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n;
char s[N];
long long ans;

int digitt(char c) {
	return c - '0' - 1;
}

void solve() {
	map<int, int> mp;
	mp.clear();
	cin >> n;
	cin >> s + 1;
	ans = 0;
	mp[0] = 1;
	int now = 0;
	for(int i = 1; i <= n; i++) {
		now += digitt(s[i]);
		ans += mp[now];
		mp[now]++;
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}   
	return 0;
}