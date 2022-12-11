#include <bits/stdc++.h>

const int MAXN = 1010;
typedef std::string str;
inline bool issym(char x) {
	return x == '$' || x == '^' || x == '#' || x == '&' || x == '=';
}
typedef std::vector<str> V;
V tokenize(str buf) {
	buf += '$';
	int lst = 0;
	V res;
	for (int i = 0, sz = buf.length(); i != sz; ++i) {
		if (issym(buf[i])) {
			res.push_back(buf.substr(lst, i - lst));
			if (i != sz - 1)
				res.push_back(buf.substr(i, 1));
			lst = i + 1;
		}
	}
	return res;
}
struct edge {
	str opt;
	int lhs, rhs;
} ;
std::map<int, edge> frm;
std::map<str, int> pool;
int idx;
std::map<int, str> name;
std::set<str> pragma;
void alloc(str x) {
	if (!pool.count(x)) {
		pool[x] = ++idx;
		name[idx] = x;
		pragma.insert(x);
	}
}
str getbyid(int x) {
	static char buf[10];
	sprintf(buf, "d%d", x);
	return str(buf);
}
str getn(int x) {
	if (!name.count(x)) {
		static int cnt = 0;
		while (pragma.count(getbyid(cnt))) ++cnt;
		name[x] = getbyid(cnt++);
	}
	return name[x];
}
std::vector<str> ans;
std::set<int> vis;
void dfs(int u) {
	if (vis.count(u)) return ;
	vis.insert(u);
	if (!frm.count(u)) return ;
	dfs(frm[u].lhs);
	dfs(frm[u].rhs);
	ans.push_back(getn(u) + "=" + getn(frm[u].lhs) + frm[u].opt + getn(frm[u].rhs));
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	while (n --> 0) {
		str x; std::cin >> x;
		V ret = tokenize(x);
		str lval = ret[0], lhs = ret[2], opt, rhs;
		alloc(lhs);
		if (ret.size() > 3) {
			opt = ret[3], rhs = ret[4];
			alloc(rhs);
			str full = getn(pool[lhs]) + opt + getn(pool[rhs]);
			if (pool.count(full)) {
				pool[lval] = pool[full];
			} else {
				++idx;
				frm[idx].opt = opt;
				frm[idx].lhs = pool[lhs];
				frm[idx].rhs = pool[rhs];
				pool[full] = pool[lval] = idx;
			}
		} else {
			pool[lval] = pool[lhs];
		}
	}
	if (!pool.count("res")) return std::cout << 0 << std::endl, 0;
	int res = pool["res"];
	if (!frm.count(res) && name[res] != "res")
		ans.push_back("res=" + name[res]);
	name[res] = "res";
	dfs(res);
	std::cout << ans.size() << '\n';
	for (auto t : ans) std::cout << t << '\n';
	return 0;
}