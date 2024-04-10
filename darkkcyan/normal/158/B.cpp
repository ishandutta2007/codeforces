#include <bits/stdc++.h>
using namespace std;

#define long long long
#define ve vector
#define ii pair<int, int>
#define ll pair<long, long>
#define sz(v) ((int) (v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define xx first
#define yy second
#define pb push_back

int main() {
	int n;
	long cnt[5] = {0};
	cin >> n;
	while (n--) {
		int a; cin >> a; ++cnt[a];
	}
	
	while (cnt[1] > 0 and cnt[3] > 0) {
		--cnt[3];
		--cnt[1];
		++cnt[4];
	}
	
	while (cnt[1] > 1 and cnt[2] > 0) {
		cnt[1] -= 2;
		cnt[2] --;
		++cnt[4];
	}
	while (cnt[1] > 0 and cnt[2] > 0) {
		--cnt[1];
		--cnt[2];
		++cnt[4];
	}
	long ans = cnt[4] + cnt[3] + (cnt[2] + 1) / 2 + cnt[1] / 4 + (cnt[1] % 4 > 0);
	
	cout << ans;
	
	return 0;
}