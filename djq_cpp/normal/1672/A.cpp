#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

void solve()
{
	int n, s = 0, a;
	scanf("%d", &n);
	rep(i, n) {
		scanf("%d", &a);
		s += a - 1;
	}
	if(s & 1) printf("errorgorn\n");
	else printf("maomao90\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}