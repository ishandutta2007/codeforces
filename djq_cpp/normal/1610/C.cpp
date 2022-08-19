#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005], b[200005];
bool check(int x)
{
	int cl = 0;
	rep(i, n) if(cl <= b[i] && x - cl - 1 <= a[i]) cl ++;
	return cl >= x;
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &a[i], &b[i]);
	int l = 0, r = n;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}