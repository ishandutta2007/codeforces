//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int T,n,d; 
int ans,lim;

int main () {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&d);
		lim = sqrt(d);
		ans = INF;
		for(register int i = 0;i <= 2 * lim; ++i)
			ans = min(ans,(int)(i + ceil(1.0 * d / (i + 1))));
		printf(ans <= n ? "YES\n" : "NO\n");
	}
	return 0;
}