#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 5005;
const ll INF = 1e18;

ll dp[MAX][MAX];
ll x[MAX], a[MAX], b[MAX], c[MAX], d[MAX];
int n, poc, kraj;

ll Rek(int poz, int brk)
{
	if (brk < 0 || (poz > 0 && brk == 0))
		return INF;

	if (poz == n) {
		if (brk == 1)
			return 0;
		return INF;
	}

	if (poz > poc && poz > kraj && brk <= 1)
		return INF;

	int imampoc = 0, imamkraj = 0;
	if (poz > poc)
		imampoc = 1;
	if (poz > kraj)
		imamkraj = 1;

	if (dp[poz][brk] != -2 * INF)
		return dp[poz][brk];

	ll ret = INF;

	//keljim se desno
	if (poz != poc && brk) {
		if (!(poz == kraj && kraj > poc && brk == 1 && poz != n - 1))
			if (!(imamkraj && brk == 1))
				ret = min(ret, a[poz] + (poz == kraj ? x[poz] : d[poz]) + Rek(poz+1, brk));
	}

	//keljim se lijevo
	if (poz != kraj && brk) {
		if (!(poz == poc && poc > kraj && brk == 1 && poz != n - 1))
			if (!(imampoc && brk == 1))
				ret = min(ret, c[poz] + (poz == poc ? x[poz] : b[poz]) + Rek(poz+1, brk));
	}

	//spajam ih
	if (poz != poc && poz != kraj && brk > 1)
		ret = min(ret, 2 * x[poz] + a[poz] + c[poz] + Rek(poz+1, brk-1));

	//samostalan
	if (poz == poc)	
		ret = min(ret, -x[poz] + d[poz] + Rek(poz+1, brk+1));

	if (poz == kraj)
		ret = min(ret, -x[poz] + b[poz] + Rek(poz+1, brk+1));

	if (poz != poc && poz != kraj)
		ret = min(ret, -2 * x[poz] + d[poz] + b[poz] + Rek(poz+1, brk+1));

	return dp[poz][brk] = ret;
}

int main()
{
	scanf("%d%d%d", &n, &poc, &kraj);

	for (int i=0; i<n; i++)
		scanf("%lld", &x[i]);

	for (int i=0; i<n; i++)
		scanf("%lld", &a[i]);

	for (int i=0; i<n; i++)
		scanf("%lld", &b[i]);

	for (int i=0; i<n; i++)
		scanf("%lld", &c[i]);
	
	for (int i=0; i<n; i++)
		scanf("%lld", &d[i]);

	memset(dp, -1, sizeof dp);

	poc--;
	kraj--;
	for (int i=0; i<MAX; i++)
		for (int j=0; j<MAX; j++)
			dp[i][j] = -2 * INF;

	printf("%lld\n", Rek(0, 0));

	return 0;
}