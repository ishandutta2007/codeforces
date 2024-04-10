#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
typedef long long ll;
int a[MAX_N];
ll s[25][25],cnt[25];
ll f[1<<20|5],g[25][1<<20|5];
int key[1<<20|5];
int main(){
	for(int i=1;i<=20;++i) key[1<<i-1]=i;
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		++cnt[a[i]];
	}
	for(int i=1;i<=20;++i){
		int d=0;
		for(int j=1;j<=n;++j)
			if(a[j]==i) ++d;
			else s[i][a[j]]+=cnt[i]-d;
	}
	for(int i=1;i<=20;++i)
		for(int sta=1;sta<1<<20;++sta)
			g[i][sta]=g[i][sta-(sta&-sta)]+s[i][key[sta&-sta]];
	f[0]=0;
	for(int sta=1;sta<1<<20;++sta){
		f[sta]=1e18;
		for(int i=1;i<=20;++i)
			if(sta&(1<<i-1))
				f[sta]=min(f[sta],f[sta-(1<<i-1)]+g[i][(1<<20)-1-sta]);
	}
	printf("%lld\n",f[(1<<20)-1]);
	return 0;
}