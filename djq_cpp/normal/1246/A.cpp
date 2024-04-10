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
	LL n, p;
	cin >> n >> p;
	rep1(i, 50) if(__builtin_popcountll(n - p * i) <= i && n - p * i >= i) {
		printf("%d\n", i);
		return 0;
	}
	printf("-1\n");
	return 0;
}