//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e6 + 10;
const int INF = 1e12 + 10;

int n,lim;
int a[MAXN],pos;
int now1 = 1,now2 = 1;
int ans1 = INF,ans2 = INF;

void DFS(int x) {
	if(x > pos) {
		if(max(now1,now2) < max(ans1,ans2))
			ans1 = now1,ans2 = now2;
		return;
	}
	now1 *= a[x];
	DFS(x + 1);
	now1 /= a[x];
	now2 *= a[x];
	DFS(x + 1);
	now2 /= a[x];
}

signed main () {
	scanf("%lld",&n);
	lim = n;
	for(register int i = 2;i * i <= lim; ++i) {
		if(n % i) continue;
		a[++pos] = 1;
		while(n % i == 0) a[pos] *= i,n /= i;
	}
	if(n != 1) a[++pos] = n;
	DFS(1);
	printf("%lld %lld",min(ans1,ans2),max(ans1,ans2));
	return 0;
}