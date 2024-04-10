//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 220000;

char s[N], t[N];
vector<pair<int, int> > A, B, C, D, ans;

vector<pair<int, int> > compress(char *s) {
	int n = strlen(s), len = 0;
	vector<pair<int, int> > ret;
	for (int i = 0; i < n; i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			if (len > 0) ret.emplace_back(s[i - 1] - 'a', len);
			len = 0;
		}
		len++;
	}
	if (len > 0) ret.emplace_back(s[n - 1] - 'a', len);
	reverse(ret.begin(), ret.end());
	return ret;
}

void Swap(int na, int nb) {
	int sa = 0;
	C.clear();
	while (na--) {
		sa += A.back().second;
		C.push_back(A.back());
		A.pop_back();
	}
	reverse(C.begin(), C.end());
	int sb = 0;
	D.clear();
	while (nb--) {
		sb += B.back().second;
		D.push_back(B.back());
		B.pop_back();
	}
	reverse(D.begin(), D.end());
	ans.emplace_back(sa, sb);
	for (auto t : C) {
		if (!B.empty() && B.back().first == t.first) B.back().second += t.second;
		else B.push_back(t);
	}
	for (auto t : D) {
		if (!A.empty() && A.back().first == t.first) A.back().second += t.second;
		else A.push_back(t);
	}
}

void Print(int flg) {
	cout << ans.size() << endl;
	for (auto t : ans) {
		if (flg) swap(t.first, t.second);
		cout << t.first << ' ' << t.second << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> s >> t;
	A = compress(s);
	B = compress(t);
	bool flg = 0;
	if (A.size() > B.size()) {
		swap(A, B);
		flg = 1;
	}
	if (A.size() == 1 && B.size() == 1) {
		cout << 0 << endl;
		return 0;
	}
	if (A.size() == 1) {
		int a = A.back().first;
		int b = B.back().first;
		if (a == b) {
			Swap(0, B.size() / 4 * 2 + 1);
		} else {
			Swap(1, B.size() / 4 * 2 + 1);
		}
	} else {
		int a = A.back().first;
		int b = B.back().first;
		if (a == b) {
			int diff = B.size() - A.size();
			if (diff % 4 == 3) {
				Swap(1, 2);
				diff = B.size() - A.size();
			}
			Swap(0, diff / 4 * 2 + 1);
		} else {
			int diff = B.size() - A.size();
			if (diff % 4 == 3) {
				Swap(1, diff / 4 * 2 + 3);
			} else {
				Swap(1, diff / 4 * 2 + 1);
			}
		}
	}
	while (max(A.size(), B.size()) > 1) Swap(1, 1);
	Print(flg);
	return 0;
}