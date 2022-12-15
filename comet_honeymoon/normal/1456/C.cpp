#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

const int maxN = 500005;
int N, K;
int nC[maxN], lenn, pC[maxN], lenp;
ll SnC[maxN], SSnC[maxN];
ll SpC, SSpC;
int cnt[maxN], cpos = 1;

signed main() {
	scanf("%lld%lld", &N, &K); K++;
	for(int i = 1; i <= N; i++) {
		int x; scanf("%lld", &x);
		if(x < 0) nC[++lenn] = x; else pC[++lenp] = x;
	}
	sort(nC + 1, nC + lenn + 1); sort(pC + 1, pC + lenp + 1);
	
	for(int i = lenn; i; i--) SnC[i] = SnC[i + 1] + nC[i], SSnC[i] = SSnC[i + 1] + 1LL * nC[i] * i;
	for(int i = 1; i <= lenp; i++) SpC += pC[i], SSpC += 1LL * pC[i] * i;
	
	ll ans = SSnC[1] - SnC[1] + SSpC - 1LL * (1 - lenn) * SpC, tans = 0;
	for(int i = 1; i <= lenn; i++) {
		tans += (cnt[cpos]++) * nC[i];
		cpos = cpos == K ? 1 : cpos + 1;
		ll nowans = tans;
		nowans += SSnC[i + 1] - 1LL * (i + 1 - cnt[1]) * SnC[i + 1];
		nowans += SSpC - 1LL * (1 - (cnt[1] + lenn - i)) * SpC;
		ans = max(ans, nowans);
		
		nowans = tans;
		nowans += SSnC[i + 1] - 1LL * (i + 1 - cnt[K]) * SnC[i + 1];
		nowans += SSpC - 1LL * (1 - (cnt[K] + lenn - i)) * SpC;
		ans = max(ans, nowans);
	}
	printf("%lld\n", ans);
}