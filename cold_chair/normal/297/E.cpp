#include<cstdio>
#include<cstring>
#include<algorithm>
#define low(a) ((a) & -(a))
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
#define mem(a) memset(a, 0, sizeof a)
using namespace std;

const int N = 2e5 + 5;

int n, f[N], p[N], q[N], w[N];
struct node {
	int x, y, i;
} a[N];
ll ans;

int cmp(node a, node b) {
	return a.x < b.x;
}

int cmp2(node a, node b) {
	return a.y > b.y;
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) {
		scanf("%d %d", &a[i].x, &a[i].y);
		if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
	}
	sort(a + 1, a + n + 1, cmp);
	fo(i, 1, n) {
		w[a[i].x] = -i; w[a[i].y] = i;
	}
	mem(f);
	fo(i, 1, n) {
		int x = a[i].x;
		while(x) p[i] += f[x], x -= low(x);
		x = 2 * n;
		while(x) p[i] += f[x], x -= low(x);
		x = a[i].y;
		while(x) p[i] -= f[x], x -= low(x);
		x = a[i].y;
		while(x <= 2 * n) f[x] ++, x += low(x);
	}
	mem(f);
	fd(i, n, 1) {
		int x = a[i].y;
		while(x) q[i] += f[x], x -= low(x);
		x = a[i].x;
		while(x) q[i] -= f[x], x -= low(x);
		x = a[i].y;
		while(x <= 2 * n) f[x] ++, x += low(x);
	}
	fo(i, 1, n) a[i].i = i;
	int tt = 0;
	fd(i, 2 * n, 1) {
		if(w[i] > 0) {
			p[w[i]] += tt;
		} else tt ++;
	}
	ans = (ll) n * (n - 1) * (n - 2) / 3;
	fo(i, 1, n) ans -= (ll) (p[i] + q[i]) * (n - p[i] - q[i] - 1) + (ll) p[i] * q[i] * 2;
	ans /= 2;
	printf("%I64d", ans);
}