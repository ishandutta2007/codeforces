#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, a[200005], c2[35];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) c2[__builtin_ctz(a[i])] ++;
	
	int t = 1, ans = 0;
	for(int i = 29; i >= 0; i --) if(c2[i]) {
		int nt = t;
		rep(j, c2[i]) nt = nt * 2 % MOD;
		if(i >= 1) ans = (ans + 1ULL * nt * (MOD + 1) / 2 - t + MOD) % MOD;
		else ans = (ans + 1ULL * nt - t + MOD) % MOD;
		t = nt;
	}
	printf("%d\n", ans);
	return 0;
}