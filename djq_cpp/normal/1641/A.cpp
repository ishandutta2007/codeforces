#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, x, a[200005];
multiset<int> S;
void solve()
{
	scanf("%d%d", &n, &x);
	int ret = n;
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	S.clear();
	rep(i, n) if(a[i] % x == 0 && S.find(a[i] / x) != S.end()) {
		S.erase(S.find(a[i] / x)); ret -= 2;
	} else S.insert(a[i]);
	printf("%d\n", ret);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}