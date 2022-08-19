#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
double prob[1005], tot[1005];
bool hv[1005];
double f[1005][1005];
double ans[1005];

int main()
{
	scanf("%d", &n);
	rep(i, n) rep(j, n) {
		scanf("%lf", &f[i][j]);
		f[i][j] /= 100;
	}
	
	rep(i, n - 1) prob[i] = 1;
	
	rep(i, n) {
		double cans = 1.0 / 0.0;
		int cur = -1;
		if(i == 0) {
			cans = 0;
			cur = n - 1;
		} else rep(j, n) if(!hv[j] && prob[j] != 1 && cans > (tot[j] + 1) / (1 - prob[j])) {
			cans = (tot[j] + 1) / (1 - prob[j]);
			cur = j;
		}
		hv[cur] = true;
		ans[cur] = cans;
		rep(j, n) if(!hv[j]) {
			tot[j] += prob[j] * f[j][cur] * ans[cur];
			prob[j] *= 1 - f[j][cur];
		}
	}
	
	printf("%lf\n", ans[0]);
	return 0;
}