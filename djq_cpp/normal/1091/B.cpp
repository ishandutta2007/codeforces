#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n;
PII a[1005], b[1005]; 

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &a[i].first, &a[i].second);
	rep(i, n) scanf("%d%d", &b[i].first, &b[i].second);
	PII ma = MP(-INF, -INF), mb = MP(INF, INF);
	rep(i, n) {
		ma = max(ma, a[i]);
		mb = min(mb, b[i]);
	}
	printf("%d %d\n", ma.first + mb.first, ma.second + mb.second);
	return 0;
}