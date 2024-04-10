#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[105];
int cnt[105];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) cnt[a[i]] ++;
	
	int ret = 0;
	rep1(i, 100) if(cnt[i]) {
		ret ++;
		for(int j = i; j <= 100; j += i) cnt[j] = 0;
	}
	printf("%d\n", ret);
	return 0;
}