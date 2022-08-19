#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, a[100005];
bool pri[100005];
vector<PII> fac[100005];
vector<PII> afac[100005], afi[100005];

int main()
{
	LL ans = 0;
	scanf("%d%d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	
	rep1(i, 100000) pri[i] = i != 1;
	rep1(i, 100000) if(pri[i]) {
		for(int j = i; j <= 100000; j += i) {
			int cnt = 0, cj = j;
			while(cj % i == 0) {
				cj /= i;
				cnt ++;
			}
			if(cnt % k != 0) fac[j].push_back(MP(i, cnt % k));
		}
		for(int j = i * 2; j <= 100000; j += i) pri[j] = false;
	}
	
	rep(i, n) afi[i] = afac[i] = fac[a[i]];
	rep(i, n) rep(j, afi[i].size()) afi[i][j].second = k - afi[i][j].second;
	rep(i, n) if(afi[i] == afac[i]) ans --;
	
	sort(afac, afac + n);
	sort(afi, afi + n);
	int p0 = 0, p1 = 0;
	while(p0 < n && p1 < n)
	if(afac[p0] < afi[p1]) p0 ++;
	else if(afac[p0] > afi[p1]) p1 ++;
	else {
		int np0 = p0, np1 = p1;
		while(p0 < n && afac[np0] == afac[p0]) p0 ++;
		while(p1 < n && afi[np1] == afi[p1]) p1 ++;
		ans += 1LL * (p0 - np0) * (p1 - np1);
	}

	ans /= 2;
	printf("%lld\n", ans);
	return 0;
}