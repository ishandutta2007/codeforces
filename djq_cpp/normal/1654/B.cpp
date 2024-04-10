#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
char S[200005];
bool occ[256];
void solve()
{
	scanf("%s", S);
	n = strlen(S);
	memset(occ, 0, sizeof(occ));
	int pos = n;
	for(int i = n - 1; i >= 0; i --) if(!occ[S[i]]) {
		occ[S[i]] = true; pos = i;
	}
	printf("%s\n", S + pos);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}