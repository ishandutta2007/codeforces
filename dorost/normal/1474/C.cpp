/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N];

void solve() {
	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	sort(a, a + n);
	map <int, int> mpx;
	set <int> stx;
	for (int i = 0; i < n; i++) {
		mpx[a[i]]++;
		stx.insert(a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		map <int, int> mp = mpx;
		set <int> st = stx;
		int s = a[i] + a[n - 1];
		bool f = true;
		int x = a[n - 1];
		mp[a[i]]--;
		mp[a[n - 1]]--;
		if (mp[a[i]] == 0)
			st.erase(a[i]);
		if (mp[a[n - 1]] == 0)
			st.erase(a[n - 1]);
		vector <pair <int, int>> v;
		while (st.size()) {
			int h = *st.rbegin();
			mp[h]--;
			if (!mp[x - h]) {
				f = false;
				break;
			}
			v.push_back({h, x - h});
			mp[x - h]--;
			if (mp[h] == 0)
				st.erase(h);
			if (mp[x - h] == 0)
				st.erase(x - h);
			x = max(h, x - h);
		}
		if (f) {
			printf("YES ");
			printf("%d ", s);
			printf("%d %d ", a[i], a[n - 1]);
			for (auto [y, u] : v) {
				printf("%d %d ", y, u);
			}
			return;
		}
	}
	printf("NO ");
}

int32_t main() {
	int t = 1;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}