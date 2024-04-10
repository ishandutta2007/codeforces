#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[100005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	int l = n, r = -1, c = 0;
	rep(i, n) if(a[i] != 0) {
		l = min(l, i); r = max(r, i); c ++;
	}
	if(c == 0) printf("0\n");
	else if(c == r - l + 1) printf("1\n");
	else printf("2\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}