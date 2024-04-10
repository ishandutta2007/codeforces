#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;
const int M = (int)1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= M) {
		return a - M;
	}
	if (a < 0) {
		return a + M;
	}
	return a;
}

int mul(int a, int b) {
	return a * (ll)b % M;
}

int pw(int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}

int dv(int a, int b) {
	return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
	a = add(a, b);
}

void mulup(int& a, int b) {
	a = mul(a, b);
}

const int N = (int)1e5 + 7;
int n;
int a[N];
int aib[N];
int aux__lft[N];
int aux__rgh[N];

void clraib() {
	for (int i = 1; i <= n; i++) aib[i] = 0;
}

void addaib(int i, int x) {
	while (i <= n) {
		aib[i] += x;
		i += i & (-i);
	}
}

int getaib(int i) {
	int sol = 0;
	while (i) {
		sol += aib[i];
		i -= i & (-i);
	}
	return sol;
}

vector<int> inds[N];
vector<int> isvalid[N];
vector<int> x[N];
vector<int> y[N];
int whatpos[N];
int thesolution[N];

int solhere[N];
int sumofall;

struct Tr {
	int dim;
	vector<int> aib1, aib2;

	struct Node {
		int ret = 0;
		int sum = 0;
		int cnt = 0;
	};

	Node join2(Node a, Node b) {
		int ret = add(a.ret, b.ret);
		int sum = add(a.sum, b.sum);
		int cnt = add(a.cnt, b.cnt); // merge si a.cnt + b.cnt lol
		addup(ret, mul(b.sum, a.cnt));
		return { ret, sum, cnt };
	}

	Node join1(Node a, Node b) {
		int ret = add(a.ret, b.ret);
		int sum = add(a.sum, b.sum);
		int cnt = add(a.cnt, b.cnt); // merge si a.cnt + b.cnt lol
		addup(ret, mul(a.sum, b.cnt));
		return { ret, sum, cnt };
	}

	vector<Node> t1;
	vector<Node> t2;

	Tr(int dim) :
		dim(dim),
		aib1(dim + 1),
		aib2(dim + 1),
		t1(4 * dim + 7),
		t2(4 * dim + 7) {

		assert((int)t1.size() == (int)t2.size());
	}

	void set2(int v, int tl, int tr, int i, int rt, int ct) {
		assert(0 <= v && v < (int)t1.size());
		if (tr < i || i < tl) return;

		if (tl == tr) {
			t2[v].ret = 0;
			t2[v].sum = rt;
			t2[v].cnt = ct;
			return;
		}
		int tm = (tl + tr) / 2;
		set2(2 * v, tl, tm, i, rt, ct);
		set2(2 * v + 1, tm + 1, tr, i, rt, ct);
		t2[v] = join2(t2[2 * v], t2[2 * v + 1]);
	}

	Node get2(int v, int tl, int tr, int l, int r) {
		assert(0 <= v && v < (int)t1.size());
		if (r < tl || tr < l) return { 0, 0 };
		if (l <= tl && tr <= r) return t2[v];
		int tm = (tl + tr) / 2;

		return join2(get2(2 * v, tl, tm, l, r), get2(2 * v + 1, tm + 1, tr, l, r));
	}


	void set2(int i, int rt, int ct) {
		set2(1, 0, dim - 1, i, rt, ct);
	}

	Node get2(int l, int r) {
		return get2(1, 0, dim - 1, l, r);
	}


	void set1(int v, int tl, int tr, int i, int rt, int ct) {
		assert(0 <= v && v < (int)t1.size());
		if (tr < i || i < tl) return;

		if (tl == tr) {
			t1[v].ret = 0;
			t1[v].sum = rt;
			t1[v].cnt = ct;
			return;
		}
		int tm = (tl + tr) / 2;
		set1(2 * v, tl, tm, i, rt, ct);
		set1(2 * v + 1, tm + 1, tr, i, rt, ct);
		t1[v] = join1(t1[2 * v], t1[2 * v + 1]);
	}

	Node get1(int v, int tl, int tr, int l, int r) {
		assert(0 <= v && v < (int)t1.size());
		if (r < tl || tr < l) return { 0, 0 };
		if (l <= tl && tr <= r) return t1[v];
		int tm = (tl + tr) / 2;

		return join1(get1(2 * v, tl, tm, l, r), get1(2 * v + 1, tm + 1, tr, l, r));
	}


	void set1(int i, int rt, int ct) {
		set1(1, 0, dim - 1, i, rt, ct);
	}

	Node get1(int l, int r) {
		return get1(1, 0, dim - 1, l, r);
	}

	void addaib1(int pos, int x) {
		assert(1 <= pos && pos <= dim);
		while (pos <= dim) addup(aib1[pos], x), pos += pos & (-pos);
	}

	void addaib2(int pos, int x) {
		assert(1 <= pos && pos <= dim);
		while (pos <= dim) addup(aib2[pos], x), pos += pos & (-pos);
	}

	int getaib1(int pos) {
		assert(0 <= pos && pos <= dim);
		int sol = 0;
		while (pos) addup(sol, aib1[pos]), pos -= pos & (-pos);
		return sol;
	}

	int getaib2(int pos) {
		assert(0 <= pos && pos <= dim);
		int sol = 0;
		while (pos) addup(sol, aib2[pos]), pos -= pos & (-pos);
		return sol;
	}
};

vector<Tr> trs;

int total;

void toggle(int index) {

	int color = a[index];

	addup(sumofall, -solhere[color]);
	{
		int p = whatpos[index];
		int delta = 0;
		int sz = (int)inds[color].size();
		{
			{
				addup(delta, mul(trs[color].getaib1(p), trs[color].getaib2(sz - p - 1)));
			}
			{
				addup(delta, mul(y[color][p], trs[color].get1(0, p - 1).ret));
			}
			{
				addup(delta, mul(x[color][p], trs[color].get2(p + 1, sz).ret));
			}
		}

		isvalid[color][p] ^= 1;

		if (isvalid[color][p]) trs[color].addaib1(p + 1, x[color][p]); else trs[color].addaib1(p + 1, add(0, -x[color][p]));
		if (isvalid[color][p]) trs[color].addaib2(sz - p, y[color][p]); else trs[color].addaib2(sz - p, add(0, -y[color][p]));

		if (isvalid[color][p]) {
			trs[color].set1(p, x[color][p], 1);
			trs[color].set2(p, y[color][p], 1);
		}
		else {
			trs[color].set1(p, 0, 0);
			trs[color].set2(p, 0, 0);
		}

		if (isvalid[color][p] == 1) {
			addup(solhere[color], +delta);
		}
		else {
			addup(solhere[color], -delta);
		}
	}
	addup(sumofall, solhere[color]);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	{ // try a better <faster> normalization tehnique
		map<int, int> tr;
		for (int i = 1; i <= n; i++) {
			tr[a[i]] = 0;
		}
		int y = 0;
		for (auto& it : tr) {
			it.second = ++y;
		}
		for (int i = 1; i <= n; i++) {
			a[i] = tr[a[i]];
		}
	}


	{
		{
			clraib();
			for (int i = 1; i <= n; i++) {
				aux__lft[i] = getaib(a[i]);
				addaib(a[i], 1);
			}
		}
		{
			clraib();
			for (int i = n; i >= 1; i--) {
				aux__rgh[i] = getaib(a[i]);
				addaib(a[i], 1);
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		whatpos[i] = (int)inds[a[i]].size();
		inds[a[i]].push_back(i);
		isvalid[a[i]].push_back(0);
		x[a[i]].push_back(aux__lft[i]);
		y[a[i]].push_back(aux__rgh[i]);
	}
	for (int i = 0; i <= n; i++) {
		trs.push_back(Tr((int)inds[i].size()));
	}
	for (int i = 1; i <= n; i++) {
		toggle(i);
	}

	int qq;
	cin >> qq;
	while (qq--) {
		{
			int type, i;
			cin >> type >> i;
			toggle(i);
		}
		cout << sumofall << "\n";
	}
}