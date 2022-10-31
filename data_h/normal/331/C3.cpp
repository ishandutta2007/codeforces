#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 1100000;

long long n;
int a[20];
long long ans = 0, mi[30];
map<long long, long long> cnt[10];
map<long long, int> decr[10];

long long dfs(int Max, long long n) {
	if (cnt[Max].count(n))
		return cnt[Max][n];
	if (n < 10) {
		int nn = n, res = 0;
		while(nn > 0 || nn == 0 && Max > 0)
			nn -= max(nn, Max), res++;
		decr[Max][n] = nn;
		cnt[Max][n] = res;
		return res;	
	}
	int a[20], len = 0;
	long long nn = n;
	while(nn) {
		a[++len] = nn % 10;
		nn /= 10;
	}
	int Max2 = max(Max, a[len]);
	nn = n - a[len] * mi[len - 1];
	dfs(Max2, nn);
	long long fake = 0;
	fake = mi[len - 1] * a[len] + decr[Max2][nn];
	dfs(Max, fake);
	decr[Max][n] = decr[Max][fake];
	cnt[Max][n] = cnt[Max2][nn] + cnt[Max][fake];
//printf("(%d, %I64d) = %I64d %d\n", Max, n, cnt[Max][n], decr[Max][n]);
	return cnt[Max][n];
}

int main() {
	mi[0] = 1;
	for(int i = 1; i <= 30; i++)
		mi[i] = mi[i - 1] * 10;
	scanf("%I64d", &n);
	if (n == 0)
		printf("0\n");
	else if (n < 10)
		printf("1\n");
	else
		printf("%I64d\n", dfs(0, n));
	return 0;
}