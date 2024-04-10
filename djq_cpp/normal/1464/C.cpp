#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n;
LL T;
char S[100005];
int cnt[26];
bool dp[100005], ndp[100005];

int main()
{
	scanf("%d%lld%s", &n, &T, S);
	rep(i, n) S[i] -= 'a';
	
	T -= 1 << S[n - 1];
	for(int i = n - 2; i >= 0; i --) T += 1 << S[i];
	
	if(T % 2 != 0 || T < 0) {
		printf("No\n"); return 0;
	}
	T /= 2;
	
	rep(i, n - 2) cnt[S[i]] ++;
	
	dp[0] = true;
	rep(i, 26) {
		int lpos = -INF;
		for(int j = 0; j <= n; j ++) {
			if(dp[j]) lpos = j;
			ndp[j] = lpos >= j - cnt[i];
		}
		for(int j = 0; j <= n; j ++)
		dp[j] = (j << 1 | (T & 1)) <= n && ndp[j << 1 | (T & 1)];
		T >>= 1;
	}
	
	printf(T <= n && dp[T] ? "Yes\n" : "No\n");
	return 0;
}