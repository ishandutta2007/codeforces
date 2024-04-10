#include<cstdio>
#include<cstring>
#include<algorithm>
#define pp printf
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int mo = 1e9 + 7;

const int N = 2e5 + 5;

int n, l, r;
ll a[3], f[N][3];

int sum(int n, int x) {
	return n / 3 + (n % 3 >= x);
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d %d", &n, &l, &r);
	fo(i, 0, 2) a[i] = sum(r, i)  - sum(l - 1, i);
	f[0][0] = 1;
	fo(i, 1, n) {
		fo(j, 0 ,2) fo(k, 0, 2) {
			f[i][(j + k) % 3] = (f[i - 1][j] * a[k] % mo + f[i][(j + k) % 3]) % mo;
		}
	}
	pp("%I64d", f[n][0]);
}