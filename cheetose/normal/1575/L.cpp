#include<bits/stdc++.h>

using namespace std;

set<pair<int, int>> S[200001];

bool query(int i, int a, int b)
{
	auto it = S[i].upper_bound({ a,b });
	if (it == S[i].begin()) return false;
	return (--it)->second < b;
}

void insert(int i, int a, int b)
{
	auto it = S[i].upper_bound({ a,b }), r = it;
	if (it != S[i].begin() && (--it)->second <= b) return;
	S[i].emplace(a, b); it = S[i].find({ a,b });
	for (r = it; ++r != S[i].end(); r = it) {
		if (b > r->second) break;
		S[i].erase(r);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, ans = 0;
	cin >> N; S[0].emplace(0, 0);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		if (i - a >= 0) {
			int s = 0, e = ans;
			while (s <= e) {
				int m = (s + e) >> 1;
				if (query(m, i - a, a)) s = m + 1;
				else e = m - 1;
			}
			insert(s, i - a, a);
			ans = max(ans, s);
		}
	}
	cout << ans << '\n';
	return 0;
}