#include<cstdio> 
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 1e5 + 5;

int n, k, a[N];

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int p[N * 100];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &k);
	int d = 0, bz = 0;
	fo(i, 1, n) {
		scanf("%d", &a[i]);
		d = gcd(d, a[i] % k);
	}
	int x = 0;
	do {
		p[++ p[0]] = x;
		x = (x + d) % k;
	} while(x != 0);
	sort(p + 1, p + p[0] + 1);
	printf("%d\n", p[0]);
	fo(i, 1, p[0]) printf("%d ", p[i]);
}