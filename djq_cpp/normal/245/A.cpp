#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int n, cnt0 = 0, cnt1 = 0;
	scanf("%d", &n);
	rep(i, n) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if(t == 1) cnt0 += x - y;
		else cnt1 += x - y;
	}
	printf(cnt0 >= 0 ? "LIVE\n" : "DEAD\n");
	printf(cnt1 >= 0 ? "LIVE\n" : "DEAD\n");
	return 0;
}