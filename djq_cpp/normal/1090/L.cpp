#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int main()
{
	int t, n, na, nb, a, b, k;
	scanf("%d%d%d%d%d", &t, &n, &a, &b, &k);
	if(k > n) {
		printf("0\n");
		return 0;
	}
	na = n + 1 >> 1;
	nb = n >> 1;
	if(a < b) {
		swap(na, nb);
		swap(a, b);
	}
	int ans = t;
	ans = min(1LL * ans, (1LL * a * na + 1LL * b * nb) / k);
	if(k > na) ans = min(1LL * ans, 1LL * b * nb / (k - na));
	printf("%d\n", ans);
	return 0;
}