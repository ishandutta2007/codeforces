#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, q, ps[2][200005];
char S[200005];
int main()
{
	scanf("%d%d%s", &n, &q, S);
	rep(i, 2) rep(j, n - 1) ps[i][j + 1] = ps[i][j] + (S[j] == '0' + i && S[j + 1] == '0' + i);
	rep(i, q) {
		int l, r;
		scanf("%d%d", &l, &r); l --; r --;
		printf("%d\n", max(ps[0][r] - ps[0][l], ps[1][r] - ps[1][l]) + 1);
	}
	return 0;
}