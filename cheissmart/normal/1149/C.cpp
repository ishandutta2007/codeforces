#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 2e5 + 7;

int n, q;
string s;

struct node {
	int mx_abc, mx_ab, mx_bc, mx_a_or_c, mx_b, d;
	node(char c = '(') {
		if(c == '(') {
			mx_abc = mx_ab = mx_bc = -INF;
			mx_a_or_c = -INF, mx_b = 0, d = 1;
		} else {
			mx_abc = mx_ab = mx_bc = -INF;
			mx_a_or_c = -1, mx_b = -1 * -2, d = -1;
		}
	}
	friend node operator + (node lhs, node rhs) {
		node res;
		rhs.mx_ab -= lhs.d;
		rhs.mx_bc -= lhs.d;
		rhs.mx_a_or_c += lhs.d;
		rhs.mx_b -= 2 * lhs.d;
		rhs.d += lhs.d;
		res.mx_abc = max({lhs.mx_abc, rhs.mx_abc, lhs.mx_a_or_c + rhs.mx_bc, lhs.mx_ab + rhs.mx_a_or_c});
		res.mx_ab = max({lhs.mx_ab, rhs.mx_ab, lhs.mx_a_or_c + rhs.mx_b});
		res.mx_bc = max({lhs.mx_bc, rhs.mx_bc, lhs.mx_b + rhs.mx_a_or_c});
		res.mx_a_or_c = max({lhs.mx_a_or_c, rhs.mx_a_or_c});
		res.mx_b = max({lhs.mx_b, rhs.mx_b});
		res.d = rhs.d;
		return res;
	}
} t[N * 4];

void pull(int v) {
	t[v] = t[v * 2] + t[v * 2 + 1];
}

void build(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = node(s[tl]);
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	pull(v);
	debug(v, t[v].mx_abc);
}

void upd(int pos, int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		assert(pos == tl);
		t[v] = node(s[pos]);
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd(pos, v * 2, tl, tm);
	else upd(pos, v * 2 + 1, tm, tr);
	pull(v);
}

signed main()
{
	IO_OP;

	cin >> n >> q >> s;
	n *= 2;
	s = "(" + s + ")";
	assert(SZ(s) == n);

	build();

	cout << t[1].mx_abc + 2 << '\n';
	while(q--) {
		int a, b;
		cin >> a >> b;
		swap(s[a], s[b]);
		upd(a), upd(b);
		cout << t[1].mx_abc + 2 << '\n';
	}
	
}