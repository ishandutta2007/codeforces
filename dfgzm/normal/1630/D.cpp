#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n,m,T;
long long ans1,ans2;
int a[maxn],cnt[maxn],v[maxn];
int gcd(int a,int b){
	return b==0? a:gcd(b,a%b);
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans1=ans2=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),ans1+=abs(a[i]),ans2+=abs(a[i]);
		int g=0;
		for(int i=1,x;i<=m;i++)
			scanf("%d",&x),g=gcd(g,x);
		for(int i=0;i<g;i++)
			cnt[i]=0,v[i]=1e9+1;
		for(int i=1;i<=n;i++){
			if(a[i]<0)
				cnt[i%g]^=1;
			v[i%g]=min(v[i%g],abs(a[i]));
		}
		for(int i=0;i<g;i++){
			if(cnt[i])
				ans1-=2*v[i];
			else ans2-=2*v[i];
		}
		printf("%lld\n",max(ans1,ans2));
	}
	return 0;
}