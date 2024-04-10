#include<cstdio>
#include<algorithm>
const int N=1e5+3,INF=1e9+37;
int l,n,p,t,dp[N],pos[N],ans;
struct segment{int l,r;}a[N];
signed main(){
	int tmp;
	scanf("%d%d%d%d",&l,&n,&p,&t);
	dp[0]=0,pos[0]=-INF;
	for(int i=1,j=0;i<=n;i++){
	  scanf("%d%d",&a[i].l,&a[i].r);
	  dp[i]=dp[i-1],pos[i]=pos[i-1];
	  for(;!j||j<i&&pos[j]+t+p<=a[i].r;j++){
	  	tmp=(a[i].r-std::max(pos[j]+t,a[i].l))/p;
		if(dp[j]+tmp>dp[i]||dp[j]+tmp==dp[i]&&std::max(pos[j]+t,a[i].l)+tmp*p<pos[i]){
		  dp[i]=dp[j]+tmp;
		  pos[i]=std::max(pos[j]+t,a[i].l)+tmp*p;
		}
	  }
	  if(j)j--;
	  ans=std::max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}