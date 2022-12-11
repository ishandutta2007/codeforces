#include <bits/stdc++.h>

typedef std::string str;
std::map<str, str> M;
std::set<str> R;
str getNextToken() {
	static int dig = 1, arr[10];
	++arr[0];
	int now = 0;
	while (arr[now] == 27) arr[now] = 1, ++arr[++now];
	++dig;
	while (arr[dig - 1] == 0) --dig;
	str res;
	for (int i = dig - 1; ~i; --i)
		res += (char) (arr[i] - 1 + 'a');
	return res;
}
str getToken(str x) {
	if (R.count(x)) return x;
	if (M.count(x)) return M[x];
	if (isdigit(x[0])) return x;
	while (true) {
		str t = getNextToken();
		if (R.count(t)) continue;
		return M[x] = t;
	}
}
struct automaton {
	static const int MAXP = 3300;
	int nxt[MAXP][256], end[MAXP], tot = 1;
	bool isword[256];
	automaton() {
		isword['_'] = isword['$'] = true;
		for (int i = 0; i < 10; ++i)
			isword[i + '0'] = true;
		for (int i = 0; i < 26; ++i)
			isword[i + 'a'] = isword[i + 'A'] = true;
	}
	void insert(str buf) {
		int now = 1;
		for (char c : buf) {
			int & nt = nxt[now][c];
			if (!nt) nt = ++tot;
			now = nt;
		}
		end[now] = true;
	}
	struct iterator {
		int u, isn, isw, L;
	} ;
	iterator begin() {
		iterator res;
		res.L = res.u = 1, res.isn = true, res.isw = true;
		return res;
	}
	iterator trans(iterator it, char x) {
		it.isn &= isdigit(x);
		it.isw &= isword[x];
		if (it.L == 1) it.isw &= !isdigit(x);
		++it.L; it.u = nxt[it.u][x];
		return it;
	}
	bool valid(iterator it) {
		return it.isn || it.isw || it.u;
	}
	bool matched(iterator it) {
		return it.isn || it.isw || end[it.u];
	}
} am;
typedef automaton::iterator it;
typedef std::vector<str> V;
V tokenize(str buf) {
	const int L = buf.size();
	V res;
	for (int l = 0; l < L; ) {
		if (buf[l] == '#') break;
		int r = l, lst = -1;
		it now = am.begin();
		while (r < L && am.valid(now)) {
			now = am.trans(now, buf[r++]);
			if (am.matched(now)) lst = r;
		}
		if (lst != -1) {
			res.emplace_back(buf.begin() + l, buf.begin() + lst);
			l = lst;
		} else ++l;
	}
	return res;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int rc; std::cin >> rc;
	for (int i = 1; i <= rc; ++i) {
		str t; std::cin >> t;
		R.insert(t); am.insert(t);
	}
	std::cin >> rc;
	V sta, out;
	while (true) {
		str buf;
		getline(std::cin, buf);
		if (!std::cin.good()) break;
		for (auto t : tokenize(buf))
			sta.push_back(getToken(t));
	}
	for (auto t : sta) {
		if (out.empty()) out.push_back(t);
		else {
			V lhs = tokenize(out.back() + t), rhs, res;
			rhs = tokenize(out.back());
			rhs.emplace_back(t);
			if (lhs == rhs) out.back() += t;
			else {
				out.emplace_back(" ");
				out.emplace_back(t);
			}
		}
	}
	for (auto t : out) std::cout << t;
	std::cout << '\n';
	return 0;
}