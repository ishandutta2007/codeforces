#include<cstdio>
#include<algorithm>
const int N=1e5+3,K=1003,INF=1e9+7;
int n,m,k,a[N],b[N],g[2][N],pa[2][N],dp[N],fa[N],mx,mxp,used[N],l,r,mm,bb[N],laf,mn,tmp[N],d,q,bt[N];
inline void Update(int k,int a){for(;k&&k<=n;k+=k&-k)if(dp[bt[k]]<dp[a])bt[k]=a;}
inline int Maxp(int k){int r=0;for(;k;k-=k&-k)if(dp[bt[k]]>dp[r])r=bt[k];return r;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),(~a[i])&&(tmp[i]=a[i]);
	std::sort(tmp+1,tmp+1+n);
	for(int i=1;i<=n;i++)if(tmp[i]!=tmp[i-1])tmp[++d]=tmp[i];
	scanf("%d",&mm);
	for(int i=1;i<=mm;i++)scanf("%d",bb+i),b[i]=bb[i];
	bb[0]=0,std::sort(bb+1,bb+1+mm);
	for(int i=1;i<=mm;i++)if(bb[i]!=bb[i-1])b[++m]=bb[i];
	r=m;
	for(int i=1;i<=mm;i++)if(bb[i]==bb[i-1])b[++r]=bb[i];
	a[n+1]=INF;
	for(int i=1,j=0;i<=n;i++)
	  if(a[i]<0){
		++j;
		for(int k=1;k<=m;k++){
		  if(g[~j&1][k-1]+1>g[j&1][k])
			g[j&1][k]=g[~j&1][k-1]+1,pa[j&1][k]=pa[~j&1][k-1];
		  if(g[~j&1][k]>g[j&1][k])
			g[j&1][k]=g[~j&1][k],pa[j&1][k]=pa[~j&1][k];
		  if(g[j&1][k-1]>g[j&1][k])
			g[j&1][k]=g[j&1][k-1],pa[j&1][k]=pa[j&1][k-1];
		}
		laf=j&1;
	  }
	  else{
		q=std::lower_bound(tmp+1,tmp+1+d,a[i])-tmp;
		fa[i]=Maxp(q-1),dp[i]=dp[fa[i]]+1;
		l=std::lower_bound(b+1,b+1+m,a[i])-b-1;
		if(g[j&1][l]+1>dp[i])
		  dp[i]=g[j&1][l]+1,fa[i]=pa[j&1][l];
		r=l+1+(b[l+1]==a[i]);
		if(g[~j&1][r]<dp[i]+1)
		  g[~j&1][r]=dp[i]+1,pa[~j&1][r]=i;
		if(dp[i]>mx)mx=dp[i],mxp=i;
		Update(q,i);
	  }
	mn=m+1;
	if(g[laf][m]>mx){
	  mxp=pa[laf][m];
	  for(int i=n,j=m;i>mxp;i--)if(a[i]<1&&b[j]>a[mxp])
		a[i]=b[j],used[j]=1,mn=j,j--;
	}
	for(int i=mxp,j=mxp,k=mn-1;;i=fa[i]){
	  for(;j>i;j--)if(a[j]<0&&b[k]>a[i])a[j]=b[k],used[k]=1,k--;
	  for(;k&&b[k]>=a[i];k--);
	  if(!i)break;
	}
	for(int i=1,j=1;i<=n;i++){
	  if(a[i]<0){
		for(;used[j];++j);
		a[i]=b[j],used[j]=1;
	  }
	  printf("%d ",a[i]);
	}puts("");
	return 0;
}