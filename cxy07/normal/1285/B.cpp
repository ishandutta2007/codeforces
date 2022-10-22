//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;
const int INF = 1e9;

int T;
int n,a[MAXN],cnt[MAXN],sum;
int mincnt,maxcnt,minpos,maxpos;
bool flag;

signed main () {
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld",&n);
		sum = flag = maxcnt = 0;
		mincnt = INF;
		memset(cnt,0,sizeof cnt);
		for(register int i = 1;i <= n; ++i)
			scanf("%lld",&a[i]),sum += a[i],cnt[i] = cnt[i - 1] + a[i];
		for(register int i = 1;i <= n; ++i) {
			if(i > 1 && mincnt >= cnt[i - 1]) mincnt = cnt[i - 1],minpos = i - 1;
			if((i != n && cnt[i] >= sum) || (cnt[i] - mincnt >= sum)) {flag = true; break;}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}