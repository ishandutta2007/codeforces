#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005], b[200005], c[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	rep1(i, n) c[i] = 0;
	
	int j = 0;
	rep(i, n) if(a[i] == b[j]) {
		j ++;
		while(j < n && a[i] == b[j] && c[a[i]] > 0) {
			c[a[i]] --; j ++;
		}
	} else c[a[i]] ++;
	printf(j == n ? "YES\n" : "NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}