#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int MAXS = 35, MAXK = 200005;

int n, m, k, cnt[MAXS]; char buf[MAXK]; bool f[MAXK];

void solve(int c){
	memset(f, false, k + 1);
	f[0] = true; int i, j;
	for(i = 1; i <= c; ++ i)
		for(j = k; j >= cnt[i]; -- j)
			f[j] |= f[j - cnt[i]];
}
int main(){
	int i, j, testcase; LL ans;
	scanf("%d", &testcase);
	while(testcase --){
		scanf("%d%d%d%s", &n, &m, &k, buf);
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; i < k; ++ i)
			++ cnt[buf[i] - 'A' + 1];
		solve(26);
		for(i = n; !f[i]; ++ i) ;
		if(k - i >= m){
			printf("0\n");
			continue;
		}
		for(i = 1, ans = LL(n) * m; i <= 26; ++ i){
			swap(cnt[i], cnt[26]);
			solve(25);
			for(j = max(n - cnt[26], 0); j <= n; ++ j)
				if(f[j]) ans = min(ans, LL(n - j) * max(m - (k - cnt[26] - j), 0));
			swap(cnt[i], cnt[26]);
		} printf("%I64d\n", ans);
	} return 0;
}