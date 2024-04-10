#include<cstdio>
#include<algorithm>
typedef long long ll;
const ll INF=1e18;
const int N=2003;
int n;ll dp[N],t,s,l[N],r[N],a[N],m,c;
inline ll Div(ll a,ll b){return(a-1)/b+1;}
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",l+i,r+i,a+i);
	for(int i=1;i<=n+1;i++)dp[i]=INF;
	dp[1]=0;
	for(int i=1;i<=n;i++){
	  t=0,s=m;
	  for(int j=i+1;j<=n+1;j++){
		if(a[j-1]<=s)s-=a[j-1],t+=a[j-1],c=0;
		else{
		  if((c=Div(a[j-1]-s,m))>r[j-1]-l[j-1])break;
		  s=(m-(a[j-1]-s)%m)%m;
		  t+=a[j-1];
		}
		if(c!=r[j-1]-l[j-1]||l[j]>r[j-1]||j==n+1)dp[j]=std::min(dp[j],dp[i]+t+(j==n+1?0:s));
	  }
	}printf("%lld\n",dp[n+1]<INF?dp[n+1]:-1);
	return 0;
}