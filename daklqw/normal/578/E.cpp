#include <bits/stdc++.h>

const int MAXN = 100010;
typedef std::list<int> L;

char buf[MAXN]; int n;
L ls[MAXN]; int bak;
std::stack<int> s[2];
L lr, rl, tt;
std::vector<int> l1, l2;
inline int T(int x) { return buf[x] == 'R'; }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf + 1; n = strlen(buf + 1);
	for (int i = 1; i <= n; ++i) {
		int ch = T(i), t;
		if (!s[ch ^ 1].empty()) t = s[ch ^ 1].top(), s[ch ^ 1].pop();
		else t = ++bak;
		ls[t].push_back(i);
		s[ch].push(t);
	}
	std::cout << bak - 1 << std::endl;
	for (int i = 1; i <= bak; ++i) {
		if (T(ls[i].front()) != T(ls[i].back())) {
			L & tar = T(ls[i].front()) ? rl : lr;
			tar.splice(tar.end(), std::move(ls[i]));
		} else (T(ls[i].front()) ? l1 : l2).push_back(i);
	}
	if (l1.size() < l2.size()) std::swap(l1, l2);
	const int SZ = l2.size();
	assert(l1.size() <= l2.size() + 1);
	if (!l1.empty()) {
		tt = ls[l1[0]];
		for (int i = 0; i < SZ; ++i) {
			tt.splice(tt.end(), std::move(ls[l2[i]]));
			tt.splice(tt.end(), std::move(ls[l1[i + 1]]));
		}
	}
	if (!lr.empty() && !rl.empty()) {
		if (lr.back() > rl.back()) std::swap(lr, rl);
		lr.push_back(rl.back());
		rl.pop_back();
		lr.splice(lr.end(), std::move(rl));
	} else if (lr.empty()) std::swap(lr, rl);
	if (!lr.empty()) {
		if (!(tt.empty() || T(lr.front()) != T(tt.back())))
			std::swap(lr, tt);
		tt.splice(tt.end(), std::move(lr));
	}
	for (auto t : tt) std::cout << t << ' ';
	std::cout << std::endl;
	return 0;
}