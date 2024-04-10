#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

struct recommendation {
	int l, r;
	int max;
	double pro;
};

const int maxn = 100010;
const int maxq = 5010;
int n, q;
int a[maxn];
int amax;
recommendation re[maxq];
vi head;
vi nex[maxq];
double pro[maxq];
double f[maxq][2 * maxq];

double cal(int cur, int val) {
	if (f[cur][val + maxq] != -1.0) return f[cur][val + maxq];
	if (re[cur].max > amax + val) return 0.0;
	double tmp1 = 1.0 - re[cur].pro, tmp2 = re[cur].pro;
	if (re[cur].max == amax + val) tmp2 = 0;
	FOR(i, 0, sz(nex[cur])) {
		tmp1 *= cal(nex[cur][i], val);
		tmp2 *= cal(nex[cur][i], val - 1);
	}
	return f[cur][val + maxq] = tmp1 + tmp2;
}

void cal() {
	FOR(i, 0, maxq) FOR(j, 0, 2 * maxq) f[i][j] = -1.0;
	FOR(val, 0, q + 1) {
		pro[val] = 1.0;
		FOR(i, 0, sz(head)) {
			int cur = head[i];
			pro[val] *= cal(cur, val);
		}
	}
}

int go(int cur, int r) {
	int i = cur + 1;
	for (i = cur + 1; i < q && re[i].r <= r; i++) {
		if (cur == -1) head.push_back(i); else nex[cur].push_back(i);
		i = go(i, re[i].r);
	}
	return i - 1;
}

void solve() {
	scanf("%d%d", &n, &q);
	amax = 0;
	FOR(i, 0, n) {
		scanf("%d", a + i);
		amax = max(amax, a[i]);
	}
	FOR(i, 0, q) {
		cin>>re[i].l>>re[i].r>>re[i].pro; re[i].l--; re[i].r--;
		re[i].max = 0; FOR(j, re[i].l, re[i].r + 1) re[i].max = max(re[i].max, a[j]);
	}
	FOR(i, 0, q) FOR(j, i + 1, q) if (make_pair(re[i].l, -re[i].r) > make_pair(re[j].l, -re[j].r)) swap(re[i], re[j]);
	go(-1, INT_MAX); cal();
	ld ans = (ld) pro[q] * (amax + q);
	FOR(i, 0, q) ans -= pro[i];
	cout<<fixed<<setprecision(9)<<ans;
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}