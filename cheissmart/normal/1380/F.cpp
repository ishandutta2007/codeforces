#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353;

/*
    NOTE: remember to call build function
*/
const int N = 5e5 + 7;

int n, m;

int f1(int x) {
	return x + 1;
}
int f2(int x) {
	if(x / 10 != 1) return 0;
	return 19 - x;
}

struct T {
	int l, r;
	int ans, ansl, ansr, anslr;
	T(int val = 0) {
		l = r = val;
		ansl = ansr = 1;
		anslr = 0;
		ans = f1(val);
	}
};

T t[N * 4];
int a[N];

inline T add(T x, T y) {
	T z;
	z.l = x.l, z.r = y.r;
	z.ans = (x.ans * y.ans % M + x.ansr * y.ansl % M * f2(x.r*10+y.l) % M) % M;
	z.ansl = (x.ansl * y.ans % M + x.anslr * y.ansl % M * f2(x.r*10+y.l) % M) % M;
	z.ansr = (x.ans * y.ansr % M + x.ansr * y.anslr % M * f2(x.r*10+y.l) % M) % M;
	z.anslr = (x.ansl * y.ansr % M + x.anslr * y.anslr % M * f2(x.r*10+y.l) % M) % M;
	return z;
}

inline void pull(int v) {
	t[v] = add(t[v * 2], t[v * 2 + 1]);
}

// void db(int v) {
// 	cerr << "[" << "node " << v << ": " << t[v].ans << " " << t[v].ansl << " " << t[v].ansr << " " << t[v].anslr << " "<< t[v].l << " " << t[v].r << "]" << endl;
// }
void build(int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = T(a[tl]); // set one
		return;
	}
	int tm = (tl + tr) / 2;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm, tr);
	pull(v);
}


int qry() {
	return t[1].ans;
}

void upd(int pos, int val, int v = 1, int tl = 0, int tr = n) {
	if(tr - tl == 1) {
		t[v] = T(val); // change one
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd(pos, val, v * 2, tl, tm);
	else upd(pos, val, v * 2 + 1, tm, tr);
	pull(v);
}


signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	build();
	while(m--) {
		int x, d;
		cin >> x >> d;
		x--;
		upd(x, d);
		cout << qry() << endl;
	}
	
}