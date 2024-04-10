#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 200000;
const int inf = 10000000;
int prime[inf + 10], m, ans[MAXN];
int check[inf + 10], t, n;

int main()
{
	scanf("%d", &n);
	m = 0; t = 0;
	for(int i = 2; i <= inf; i++) {
		if (check[i] == 0) {
			prime[++m] = i;
			for(int j = i + i; j <= inf; j += i)
				check[j] = 1;
		}
	}
	//for(int i = 1; i <= m; i++)
	//	printf("%d\n", prime[i]);
	//return 0;
	for(int i = 1; i <= 1000; i++)	
		for(int j = i; j <= 1000; j++) {
			if (t == n)
				break;
			if ((long long)prime[i] * prime[j] <= inf)
				ans[++t] = prime[i] * prime[j];
		}
	sort(ans + 1, ans + n + 1);
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}