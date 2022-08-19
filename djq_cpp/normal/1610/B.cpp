#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005], b[200005];
bool check(int arr[], int len)
{
	rep(i, len) if(arr[i] != arr[len - 1 - i]) return false;
	return true;
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	if(check(a, n)) printf("YES\n");
	else for(int i = 0; i < n; i ++) if(a[i] != a[n - 1 - i]) {
		int m = 0;
		rep(j, n) if(a[j] != a[i]) b[m ++] = a[j];
		if(check(b, m)) printf("YES\n");
		else {
			m = 0;
			rep(j, n) if(a[j] != a[n - 1 - i]) b[m ++] = a[j];
			if(check(b, m)) printf("YES\n");
			else printf("NO\n");
		}
		return;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}