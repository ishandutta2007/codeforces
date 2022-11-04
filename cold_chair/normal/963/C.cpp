#include<cstdio>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int M = 1e6 + 1e5;

const int N = 2e5 + 5;

int n, b[N];

struct node {
	ll x, y, c;
} a[N];

int cmp(node a, node b) {
	if(a.x < b.x) return 1;
	if(a.x > b.x) return 0;
	return a.y < b.y;
}

int cmp2(node a, node b) {
	if(a.y < b.y) return 1;
	if(a.y > b.y) return 0;
	return a.x < b.x;
}

ll gcd(ll x, ll y) {
	return y == 0 ? x : gcd(y, x % y);
}

void halt() {
	printf("0\n");
	exit(0);
}

ll c[N], ans;

int bz[M + 1], p[M];
void Shai() {
	fo(i, 2, M)	 {
		if(!bz[i]) p[++ p[0]] = i;
		fo(j, 1, p[0]) {
			int k = i * p[j];
			if(k > M) break;
			bz[k] = 1; if(i % p[j] == 0) break;
		}
	}
}

ll solve(ll n) {
	ll s = 1;
	for(int i = 1; p[i] * p[i] <= n; i ++) if(n % p[i] == 0){
		ll v = 0;
		while(n % p[i] == 0) v ++, n /= p[i];
		s *= (v + 1);
	}
	return n > 1 ? s * 2 : s;
}

int main() {
//	freopen("c.in", "r", stdin);
	Shai();
	scanf("%d", &n);
	fo(i, 1, n) scanf("%I64d %I64d %I64d", &a[i].x, &a[i].y, &a[i].c);
	sort(a + 1, a + n + 1, cmp);
	int tmp = 0;
	fo(i, 1, n) {
		if(i == 1 || a[i].x != a[i - 1].x) tmp ++;
		b[i] = tmp;
	}
	fo(i, 1, n) a[i].x = b[i];
	sort(a + 1, a + n + 1, cmp2);
	tmp = 0;
	fo(i, 1, n) {
		if(i == 1 || a[i].y != a[i - 1].y) tmp ++;
		b[i] = tmp;
	}
	fo(i, 1, n) a[i].y = b[i];
	fo(i, 1, n) {
		if(i == 1 || a[i].y != a[i - 1].y) {
			if(a[i].x != 1) halt();
		} else if(a[i].x != a[i - 1].x + 1) halt();
	}
	int la = 1;
	fo(i, 2, n + 1) {
		if(a[i].y != a[i - 1].y || i > n) {
			ll d = a[la].c;
			fo(j, la + 1, i - 1) d = gcd(d, a[j].c);
			if(la == 1) {
				fo(j, la, i - 1) c[a[j].x] = a[j].c / d;
			} else {
				fo(j, la, i - 1) if(c[a[j].x] != a[j].c / d) halt();
			}
			la = i;
		}
	}
	ans = a[1].c;
	fo(i, 2, n) ans = gcd(ans, a[i].c);
	printf("%I64d", solve(ans));
}