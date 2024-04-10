#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e6+10;
int n,C,m;long long a[o];
int main(){
	scanf("%d%d",&n,&C);
	for(int c,d,h;n--;) scanf("%d%d%d",&c,&d,&h),a[c]=max(a[c],d*1ll*h);
	for(int i=1;i<=C;++i) for(int j=1;i*j<=C;++j) a[i*j]=max(a[i*j],a[i]*j);
	for(int i=1;i<=C;++i) a[i]=max(a[i],a[i-1]);
	scanf("%d",&m);
	for(long long d,h,ans;m--;printf("%lld ",ans)){
		scanf("%lld%lld",&d,&h);
		if(a[C]<=d*h) ans=-1;
		else for(int l=0,r=ans=C,md;l<r;ans=l) if(a[md=l+r>>1]>d*h) r=md;else l=md+1;
	}
	return 0;
}