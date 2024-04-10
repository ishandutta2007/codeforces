#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1<<21;
int T, n, m, cnt, a[N], ans[N];
ll sum;
int f(int x){
	if(!a[x]) return 0;
	int y=f(a[x<<1]>a[x<<1|1]?x<<1:x<<1|1);
	if(y) return swap(a[x], y), y;
	else if(x<1<<m) return 0;
	else return y=a[x], a[x]=0, y;
}
void solve(int x){
	if(!a[x]) return;
	for(int y; (y=f(x)); sum-=y) ans[cnt++]=x;
	solve(x<<1), solve(x<<1|1);
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m), sum=cnt=0;
		for(int i=1; i<1<<n; ++i) scanf("%d", a+i), sum+=a[i];
		solve(1);
		memset(a, 0, 4<<m);
		printf("%lld\n", sum);
		for(int i=0; i<cnt; ++i) printf("%d%c", ans[i], " \n"[i==cnt-1]);
	}
	return 0;
}