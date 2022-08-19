#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
char ch[105];
int cnt[155];

int main()
{
	scanf("%d%s", &n, ch);
	rep(i, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		int cur = ch[i] - '0';
		for(int j = 0; j <= 150; j ++) {
			if(j >= b && (j - b) % a == 0) cur ^= 1;
			cnt[j] += cur;
		}
	}
	int ans = 0;
	for(int i = 0; i <= 150; i ++) ans = max(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}