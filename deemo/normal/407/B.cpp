#include<cstdio>
#include<algorithm>

using namespace std;

const int max_n = 2e3;
const int MOD = 1e9 + 7;

int n;
long long d[max_n], a[max_n];

int main(){
	d[0] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), a[i]--;
	for (int i = 1; i <= n; i++)
		d[i] = (MOD + 2 * d[i - 1] - d[a[i - 1]] + 2) % MOD;
	printf ("%d\n", d[n]);
	return 0;
}