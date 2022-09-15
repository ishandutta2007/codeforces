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
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

const int maxx = 10010;
const int maxy = 5010;
struct Fenwick {
	int fen[maxx][maxy];
	void reset() {ms(fen, 0);}
	void add(int x, int y, int val) {
		while (x < maxx) {
			int y1 = y;
			while (y1 < maxy) {
				fen[x][y1] += val;
				y1 += y1 & -y1;
			}
			x += x & -x;
		}
	}
	int get(int x, int y) {
		int res = 0;
		while (x) {
			int y1 = y;
			while (y1) {
				res += fen[x][y1];
				y1 -= y1 & -y1;
			}
			x -= x & -x;
		}
		return res;
	}
} fw[2];

struct query {
	int type;
	int dir;
	int x, y;
	int len;
};

const int maxq = 100010;
int n, q;
query vq[maxq];
int ans[maxq];

void solve() {
	scanf("%d%d", &n, &q);
	FOR(i, 0, q) {
		scanf("%d", &vq[i].type);
		if (vq[i].type == 1) scanf("%d%d%d%d", &vq[i].dir, &vq[i].x, &vq[i].y, &vq[i].len);
		else scanf("%d%d", &vq[i].x, &vq[i].y);
	}
	FOR(t, 1, 5) {
		FOR(i, 0, 2) fw[i].reset();
		FOR(i, 0, q) {
			int x = vq[i].x, y = vq[i].y;
			if (t == 2 || t == 4) y = n - y + 1;
			if (t == 3 || t == 4) x = n - x + 1;
			if (vq[i].dir == t) {
				fw[0].add(x, y, 1);
				fw[0].add(x, y + vq[i].len + 1, -1);
				fw[1].add(x + y + vq[i].len, y, 1);
				fw[1].add(x + y + vq[i].len, y + vq[i].len + 1, -1);
			}
			else if (vq[i].type == 2) {
				ans[i] += fw[0].get(x, y) - fw[1].get(x + y - 1, y);
			}
		}
	}
	FOR(i, 0, q) if (vq[i].type == 2) printf("%d\n", ans[i]);
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}