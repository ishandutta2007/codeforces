#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int P = 998244353;
const int MOD = 1e9 + 7;
const int B = 1000000; 

int xmod(LL d)
{
	int ret = d % P;
	return ret < 0 ? ret + P : ret;
}
LL n, cnt;
int ans;
vector<int> hv[7];
LL sum[7];
void dfs0(int dep, LL val)
{
	cnt ++;
	hv[dep].push_back(xmod(cnt - val));
	if(dep == 6) return;
	rep(i, 10) dfs0(dep + 1, val * 10 + i);
}
int calc(int id, int coef)
{
	int pos = lower_bound(hv[id].begin(), hv[id].end(), P - coef) - hv[id].begin();
	return (1LL * coef * (int)hv[id].size() + sum[id] - 1LL * P * ((int)hv[id].size() - pos)) % MOD;
}
void dfs1(int dep, LL val)
{
	if(val > n) return;
	if(dep >= 1) {
		if(val * B > n / 10 && val * B + B - 1 <= n) {
			int tmp = 1;
			rep(i, 7) {
				ans = (ans + calc(i, xmod(cnt - val * tmp))) % MOD; tmp *= 10;
			}
			rep(i, 7) cnt += hv[i].size();
			return;
		}
		cnt ++; ans = (ans + xmod(cnt - val)) % MOD;
	}
	for(int i = !dep; i < 10; i ++) dfs1(dep + 1, val * 10 + i);
}

int main()
{
	scanf("%lld", &n);
	dfs0(0, 0);
	rep(i, 7) {
		sort(hv[i].begin(), hv[i].end());
		rep(j, hv[i].size()) sum[i] += hv[i][j];
	}
	cnt = 0;
	dfs1(0, 0);
	printf("%d\n", ans);
	return 0;
}