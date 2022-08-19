#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[100005], t0;
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	int m = 0; t0 = 0;
	rep(i, n) if(a[i] == 0) t0 ++;
	else a[m ++] = a[i];
	rep(i, n - 1) {
		if(t0 > 0) {
			t0 --;
			for(int j = m - 1; j >= 1; j --) a[j] -= a[j - 1];
		} else {
			m --;
			rep(j, m) a[j] = a[j + 1] - a[j];
		}
		sort(a, a + m);
		int mm = m; m = 0;
		rep(j, mm) if(a[j] == 0) t0 ++;
		else a[m ++] = a[j];
	}
	printf("%d\n", a[0]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0; 
}