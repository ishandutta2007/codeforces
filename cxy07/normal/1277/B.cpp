//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;

int T,n,x,ans;
map<int,int> to;

int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		to.clear();
		ans = 0;
		for(register int i = 1,cnt;i <= n; ++i) {
			scanf("%d",&x);
			cnt = 0;
			while(x % 2 == 0) cnt++,x >>= 1;
			if(cnt > to[x]) ans += cnt - to[x],to[x] = cnt;
		}
		printf("%d\n",ans);
	}
	return 0;
}