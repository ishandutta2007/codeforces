#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, arr[1000005], ret[1000005];
PII dat[1000005];
char S[262145];
PII tmp[131075];
int p0[131075], p1[131075], cnt[262145];
void solve(int n, int L, int ar[], int re[], PII ct[])
{
	if(n == 0) {
		re[0] = ar[0]; return;
	}
	rep(i, 1 << n) re[i] = L;
	rep(i, 2) {
		int cl = 1 << (n - 1);
		rep(j, L) cnt[j] = 0;
		rep(j, cl) cnt[ar[j << 1 | !i]] ++;
		rep1(j, L) cnt[j] += cnt[j - 1];
		for(int j = cl - 1; j >= 0; j --) p0[-- cnt[ar[j << 1 | !i]]] = j;
		rep(j, L) cnt[j] = 0;
		rep(j, cl) cnt[ar[j << 1 | i]] ++;
		rep1(j, L) cnt[j] += cnt[j - 1];
		for(int j = cl - 1; j >= 0; j --) p1[-- cnt[ar[p0[j] << 1 | i]]] = p0[j];
		rep(j, cl) p0[p1[j]] = j == 0 ? 0 : p0[p1[j - 1]] + (ar[p1[j] << 1 | !i] != ar[p1[j - 1] << 1 | !i]
		|| ar[p1[j] << 1 | i] != ar[p1[j - 1] << 1 | i]);
		rep(j, cl) ct[p0[j]] = MP(ar[j << 1 | i], ar[j << 1 | !i]);
		rep(j, cl) ar[j + (1 << n)] = p0[j];
		solve(n - 1, 1 << (n - 1), ar + (1 << n), re + (1 << n), ct + (1 << n));
		rep(j, cl) {
			cnt[j << 1] = ct[re[j + (1 << n)]].first; cnt[j << 1 | 1] = ct[re[j + (1 << n)]].second;
		}
		bool ok = false;
		rep(j, 1 << n) if(cnt[j] != re[j]) {
			ok = cnt[j] < re[j]; break;
		}
		if(ok) rep(j, 1 << n) re[j] = cnt[j];
	}
}

int main()
{
	scanf("%d%s", &n, S);
	rep(i, 1 << n) arr[i] = S[i];
	solve(n, 256, arr, ret, tmp);
	rep(i, 1 << n) printf("%c", ret[i]); printf("\n");
	return 0;
}