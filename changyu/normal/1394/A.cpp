#include<cstdio>
#include<algorithm>
#define int long long
const int N=1e5+3;
int n,m,d,a[N],b[N],na,nb,ans,sa;
bool Cmp(const int&a,const int&b){return a>b;}
signed main(){
	int t;
	scanf("%lld%lld%lld",&n,&d,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&t),t>m?a[++na]=t:b[++nb]=t;
	std::sort(a+1,a+1+na,Cmp);
	std::sort(b+1,b+1+nb,Cmp);
	for(int i=1;i<=na;i++)a[i]+=a[i-1];
	for(int i=1;i<=nb;i++)b[i]+=b[i-1];
	for(int i=0;i<=na;i++){
	  if(d*i<na-i||(d+1)*(i-1)+1>n)continue;
	  //printf("%lld\n",i);
	  if(d*(i-1)<=na-i){ans=std::max(ans,a[i]+b[nb]);continue;}
	  ans=std::max(ans,a[i]+b[nb-(d*(i-1)-(na-i))]);
	}
	printf("%lld\n",ans);
	return 0;
}