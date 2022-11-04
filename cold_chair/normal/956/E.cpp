#include<cstdio>
#include<bitset>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y ; i ++)
#define fd(i, x, y) for(int i = x; i >= y ; i --)
using namespace std;

const int N = 1e4 + 5;

int n, x, l, r, a[N], b[N], a0, b0;
bitset<10001> f, f1; ll sum;

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d %d", &n, &l, &r);
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n) {
		scanf("%d", &x);
		if(x) a[++ a0] = a[i], sum += a[i]; else b[++ b0] = a[i];
	}
	f[0] = 1; fo(i, 1, b0) f |= f << b[i];
	sort(a + 1, a + a0 + 1);
	fd(i, a0, 1) {
		f1 |= f1 << a[i]; f1 |= f;
		f |= f << a[i];
		sum -= a[i];
		if((f1 << (10000 - r + sum) >> (10000 - r + sum + l)).count()) {
			printf("%d\n", i); return 0;
		}
		if((f << (10000 - r + sum) >> (10000 - r + sum + l)).count()) {
			printf("%d\n", i - 1); return 0;
		}
	}
	printf("0");
}