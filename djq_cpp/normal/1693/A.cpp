#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	LL s = 0;
	bool i0 = false;
	rep(i, n) {
		s += a[i];
		if(s < 0 || (i0 && s > 0)) {
			printf("No\n"); return;
		}
		i0 |= s == 0;
	}
	printf(i0 ? "Yes\n" : "No\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}