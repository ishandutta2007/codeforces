#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

char ans[105][105];

int main()
{
	int T, n, k;
	scanf("%d", &T);
	while(T --) {
		scanf("%d%d", &n, &k);
		if(k * 2 > n + 1) {
			printf("-1\n"); continue;
		}
		rep(i, n) rep(j, n) ans[i][j] = '.';
		rep(i, n) ans[i][n] = 0;
		rep(i, k) ans[2 * i][2 * i] = 'R';
		rep(i, n) printf("%s\n", ans[i]);
	}
	return 0; 
}