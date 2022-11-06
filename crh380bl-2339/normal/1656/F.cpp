#include<bits/stdc++.h>
#define ll long long
#define mytz __builtin_ctzll
using namespace std;
ll a[200005],sum[200005];
__int128 ans,tmp;
void put(__int128 x){
	if(x==0)return;
	put(x/10);
	printf("%d",(int)(x%10));
}
int main(){
	int T,i,t;
	int n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		a[n+1]=1000001;
		a[0]=-a[n+1];
		for(i=1;i<=n;++i){
			sum[i]=sum[i-1]+a[i];
		}
		
		if(a[1]*(n-2)+sum[n]>0||a[n]*(n-2)+sum[n]<0){
			puts("INF");
			continue;
		}
		for(t=0;t<=n;++t){
			if(a[t]==a[t+1])continue;
			ll a1=a[n]*sum[t]+a[1]*(sum[n-1]-sum[t]);
			ll a2=(a[1]*(n-1-t)+a[n]*(t-1)+sum[n]);
			tmp=-min((__int128)a2*a[t+1],(__int128)a2*(a[t]+1))+(__int128)a1;
			if(t==0||tmp>ans)ans=tmp;
		}
		if(ans==0){
			puts("0");
			continue;
		}
		if(ans<0){
			ans=-ans;
			putchar('-');
		}
		put(ans);puts("");
	}
	return 0;
}