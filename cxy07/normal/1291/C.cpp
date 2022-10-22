//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4010;
const int INF = 2e9;

int T;
int L,R,ans,now;
int n,m,k,len,a[MAXN];
priority_queue<int> Q;

int main () {
	cin >> T;
	while(T--) {
		cin >> n >> m >> k;
		for(register int i = 1;i <= n; ++i)
			cin >> a[i];
		ans = -1,now = INF;
		k = min(k,m - 1);
		len = n - m + 1;
		for(register int i = 0;i <= k; ++i) {
			L = i + 1,R = n - k + i;
			now = INF;
			for(register int p = L;p + len - 1 <= R; ++p)
				now = min(now,max(a[p],a[p + len - 1]));
			ans = max(ans,now);
		} 
		printf("%d\n",ans);
	}
	return 0;
}