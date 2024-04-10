#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

char S[200005];
void solve()
{
	scanf("%s", S);
	int n = strlen(S), s = 0;
	rep(i, n) {
		s += S[i] == 'A' ? 1 : -1;
		if(s < 0) {
			printf("NO\n"); return;
		}
	}
	printf(S[n - 1] == 'B' ? "YES\n" : "NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}