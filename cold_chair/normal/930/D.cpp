#include<cstdio>
#include<cstring>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 4e5 + 50, M = 2e5 + 5;

int n; ll ans;

struct node {
	int x, y;
	node (int _x = 0, int _y = 0) {x = _x, y = _y;}
} a[N];

int p[N], q[N], u[N], v[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d %d", &a[i].x, &a[i].y), a[i] = node(a[i].x + a[i].y + M, a[i].x - a[i].y + M);
	memset(p, 128, sizeof p); memset(q, 128, sizeof q);
	fo(i, 1, n) p[a[i].x - 1] = max(p[a[i].x - 1], a[i].y - 1);
	fd(i, 2 * M, 0) p[i] = max(p[i], p[i + 2]);
	fo(i, 1, n) q[a[i].x + 1] = max(q[a[i].x + 1], a[i].y - 1);
	fo(i, 2, 2 * M) q[i] = max(q[i], q[i - 2]);
	memset(u, 127, sizeof u); memset(v, 127, sizeof v);
	fo(i, 1, n) u[a[i].x - 1] = min(u[a[i].x - 1], a[i].y + 1);
	fd(i, 2 * M, 0) u[i] = min(u[i], u[i + 2]);
	fo(i, 1, n) v[a[i].x + 1] = min(v[a[i].x + 1], a[i].y + 1);
	fo(i, 2, 2 * M) v[i] = min(v[i], v[i - 2]);
	fo(i, 0, 2 * M) {
		int mi = min(p[i], q[i]), mx = max(u[i], v[i]);
		if(mi >= mx) ans += (mi - mx) / 2 + 1;
	}
	printf("%I64d", ans);
}