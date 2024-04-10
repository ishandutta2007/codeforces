#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 2005, MOD = 1e9 + 7, MAXF = 200100;

int Sub(int a, int b)
{
	return (a - b + MOD) % MOD;
}

int Add(int a, int b)
{
	return (a + b) % MOD;
}

int Mul(int a, int b)
{
	return (int) (((ll) a * b) % MOD);
}

int fak[MAXF], invfak[MAXF];
int dp[MAX][2];
P toc[MAX];

int Inverz(int x)
{
	int ret = 1;

	for (int eksp = MOD - 2; eksp; eksp >>= 1, x = Mul(x, x))
		if (eksp & 1)
			ret = Mul(ret, x);

	return ret;
}

void GenFak()
{
	fak[0] = invfak[0] = 1;
	for (int i=1; i<MAXF; i++) {
		fak[i] = Mul(i, fak[i-1]);
		invfak[i] = Inverz(fak[i]);
	}
}

int Povrh(int n, int k)
{
	return Mul(fak[n], Mul(invfak[k], invfak[n-k]));
}

int Putt(int dol, int gor)
{
	return Povrh(toc[dol].X - toc[gor].X + toc[dol].Y - toc[gor].Y, toc[dol].X - toc[gor].X);
}

int main()
{
	int h, w, n;
	
	GenFak();

	scanf("%d%d%d", &h, &w, &n);

	for (int i=1; i<=n; i++)
			scanf("%d%d", &toc[i].X, &toc[i].Y);

	sort(toc + 1, toc + n + 1);
	 
	dp[0][0] = 1;
	toc[0] = P(1, 1);
	toc[n+1] = P(h, w);

	for (int i=1; i<=n+1; i++) {
		for (int j=0; j<i; j++) {
			if (toc[j].Y <= toc[i].Y) {
				dp[i][0] = Add(dp[i][0], Mul(dp[j][1], Putt(i, j)));
				dp[i][1] = Add(dp[i][1], Mul(dp[j][0], Putt(i, j)));
			}
		}
	}

	printf("%d\n", Sub(dp[n+1][1], dp[n+1][0]));

	return 0;
}