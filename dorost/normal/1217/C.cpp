/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int cnt[N];
typedef pair <int, pair <int, int>> piii;
char t[N];

void solve() {
	scanf(" %s", t);
	string s = t;
	int n = s.size ();
	int x = log2 (n) + 10;
	vector <piii> all;
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	for (int i = 1; i < x; i++){
		for (int j = 0; j < n - i + 1; j++) {
			string bin;
			for (int k = j; k < j + i; k++) {
				bin += s[k];
			}
			int num = 0;
			for (int k = 0; k < i; k++){
				num = num * 2 + (bin[k] - '0');
			}
			if (num > n || num == 0)
				continue;
			all.push_back ({num, {j, j + i}});
		}
	}
	int ans = 0;
	set <pair <int, int>> st;
	for (int i = 0; i < all.size(); i++) {
		int num = all[i].F, l = all[i].S.F, r = all[i].S.S;
		if (r - num < 0)
			continue;
		if (st.count({r - num, r}))
			continue;
		bool f = true;
		for (int j = r - num; j < l; j++) {
			if (s[j] != '0'){
				f = false;
				break;
			}
		}
		if (f)
			st.insert({r - num, r});
	}
	printf("%d ", (int)st.size());
}

int32_t main() {
	int q;
	scanf("%d", &q);
	while (q--)
		solve ();
}