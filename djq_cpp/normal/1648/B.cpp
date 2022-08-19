#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int ps[1000005], n, c;
void solve()
{
	scanf("%d%d", &n, &c);
	rep1(i, c) ps[i] = 0;
	rep(i, n) {
		int x; scanf("%d", &x);
		ps[x] ++;
	}
	rep1(i, c) ps[i] += ps[i - 1];
	rep1(i, c) if(ps[i] != ps[i - 1]) for(int j = i; j <= c; j += i) if(ps[min(c, j + i - 1)] > ps[j - 1] && ps[j / i] == ps[j / i - 1]) {
		printf("No\n"); return;
	}
	printf("Yes\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}