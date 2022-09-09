#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct Pair {int x, y; };
int n, m, curr, depth[MAXN];
vector <Pair> a[MAXN], b[MAXN];
struct Info {int pos, type, val; };
bool operator < (Info a, Info b) {
	int apos = a.pos + a.type * curr;
	int bpos = b.pos + b.type * curr;
	if (apos == bpos) return a.type < b.type;
	else return apos < bpos;
}
struct Crash {
	Info a, b;
	int when;
	void calc() {
		int apos = a.pos + a.type * curr;
		int bpos = b.pos + b.type * curr;
		when = curr - (bpos - apos + 1) / 2;
	}
};
Crash make(Info a, Info b) {
	Crash ans = (Crash) {a, b};
	ans.calc();
	return ans;
}
bool operator < (Crash a, Crash b) {
	if (a.when == b.when) return make_pair(a.a, a.b) < make_pair(b.a, b.b);
	else return a.when > b.when;
}
struct Container {
	set <Info> Val;
	set <Crash> Del;
	void EraseCrash(Info a, Info b) {
		if (a.type == -1 && b.type == 1)
			Del.erase(make(a, b));
	}
	void InsertCrash(Info a, Info b) {
		if (a.type == -1 && b.type == 1)
			Del.insert(make(a, b));
	}
	void erase(Info a) {
		set <Info> :: iterator pos = Val.find(a), suf = pos; suf++;
		if (pos != Val.begin()) {
			set <Info> :: iterator pre = pos; pre--;
			EraseCrash(*pre, *pos);
			if (suf != Val.end()) InsertCrash(*pre, *suf);
		}
		if (suf != Val.end()) EraseCrash(*pos, *suf);
		Val.erase(pos);
	}
	void insert(Info a) {
		if (a.val == 0) return;
		if (Val.find(a) != Val.end()) {
			a.val += (*Val.find(a)).val;
			erase(*Val.find(a));
		}
		if (a.val == 0) return;
		set <Info> :: iterator pos = Val.insert(a).first, suf = pos; suf++;
		if (pos != Val.begin()) {
			set <Info> :: iterator pre = pos; pre--;
			InsertCrash(*pre, *pos);
			if (suf != Val.end()) EraseCrash(*pre, *suf);
		}
		if (suf != Val.end()) InsertCrash(*pos, *suf);
	}
	void process(Crash a) {
		erase(a.a), erase(a.b);
		int tmp = a.a.val + a.b.val;
		if (tmp == 0) return;
		if (tmp > 0) a.b.val = tmp, insert(a.b);
		else a.a.val = tmp, insert(a.a);
	}
	void maintain(int timer) {
		while (!Del.empty() && timer <= (*Del.begin()).when)
			process(*Del.begin());
		curr = timer;
	}
	void debug(int pos, int timer) {
		maintain(timer);
		cerr << "Debugging In Progress. At Point " << pos << " Current Time: " << timer << endl;
		set <Info> :: iterator i;
		cerr << "Set Val: " << endl;
		for (i = Val.begin(); i != Val.end(); i++)
			cerr << (*i).pos << '(' << (*i).pos + curr * (*i).type << ')' << ' ' << (*i).type << ' ' << (*i).val << endl;
		set <Crash> :: iterator j;
		cerr << "Del Val: " << endl;
		for (j = Del.begin(); j != Del.end(); j++) {
			cerr << (*j).a.pos << '(' << (*j).a.pos + curr * (*j).a.type << ')' << ' ' << (*j).a.type << ' ' << (*j).a.val << ' ';
			cerr << (*j).b.pos << '(' << (*j).b.pos + curr * (*j).b.type << ')' << ' ' << (*j).b.type << ' ' << (*j).b.val << ' ';
			cerr << "Collide Time: " << (*j).when << endl; 
		}
	}
	void join(Container &a, int timer) {
		maintain(timer);
		if (a.Val.size() > Val.size()) {
			swap(Val, a.Val);
			swap(Del, a.Del);
		}
		set <Info> :: iterator i;
		for (i = a.Val.begin(); i != a.Val.end(); i++)
			insert(*i);
	}
	int delta(int pos) {
		Info tmp = (Info) {pos + curr, -1, 0};
		Info tnp = (Info) {pos + 1 - curr, 1, 0};
		int vtmp = 0, vtnp = 0;
		if (Val.find(tmp) != Val.end()) vtmp = -(*Val.find(tmp)).val;
		if (Val.find(tnp) != Val.end()) vtnp = (*Val.find(tnp)).val;
		return max(vtmp, vtnp);
	}
	void modify(vector <Pair> &a, int from, int to) {
		maintain(from);
		//debug(0, curr);
		for (unsigned i = 0; i < a.size(); i++) {
			int tmp = delta(a[i].x);
			a[i].y = max(0, a[i].y - tmp);
		}
		maintain(from - 1);
		//debug(0, curr);
		for (unsigned i = 0; i < a.size(); i++) {
			insert((Info) {a[i].x - curr, 1, a[i].y});
			insert((Info) {a[i].x + 1 + curr, -1, -a[i].y});
		}
		//debug(0, curr);
		maintain(to);
		//debug(0, curr);
	}
	int calcans() {
		int ans = 0, now = 0;
		set <Info> :: iterator i;
		for (i = Val.begin(); i != Val.end(); i++) {
			now += (*i).val;
			chkmax(ans, now);
		}
		return ans;
	}
} dp[MAXN];
void dfs(int pos, int fa) {
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].x != fa) {
			depth[a[pos][i].x] = depth[pos] + a[pos][i].y;
			dfs(a[pos][i].x, pos);
		}
}
void work(int pos, int fa, int last) {
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i].x != fa) {
			int tmp = a[pos][i].x;
			work(tmp, pos, depth[pos]);
			dp[pos].join(dp[a[pos][i].x], depth[pos]);
		}
	dp[pos].modify(b[pos], depth[pos], last);
	//dp[pos].debug(pos, last);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		a[x].push_back((Pair) {y, z * 2});
		a[y].push_back((Pair) {x, z * 2});
	}
	read(m);
	for (int i = 1; i <= m; i++) {
		int d, f, p;
		read(d), read(f), read(p);
		b[p].push_back((Pair) {d * 2, f});
	}
	dfs(1, 0);
	work(1, 0, -2);
	writeln(dp[1].calcans());
	return 0;
}