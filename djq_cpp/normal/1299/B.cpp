#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
PII dat[100005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &dat[i].first, &dat[i].second);
	sort(dat, dat + n);
	PII csum = MP(dat[0].first + dat[n - 1].first, dat[0].second + dat[n - 1].second);
	rep(i, n) if(csum.first != dat[i].first + dat[n - 1 - i].first || csum.second != dat[i].second + dat[n - 1 - i].second) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}