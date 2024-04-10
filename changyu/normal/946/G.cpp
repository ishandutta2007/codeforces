#include<cstdio>
#include<algorithm>
const int N=2e5+3,K=35,INF=0x3f3f3f3f;
int n,a[N],b[N],dp[N],mx,ans,rt;
#define M (L+R>>1)
struct segment_tree{
	int mx[N*35],ls[N*35],rs[N*35],t;
	void Insert(int p,int a,int L,int R,int&k){
		if(!k)k=++t;
		mx[k]=std::max(mx[k],a);
		if(L==R)return;
		p<=M?Insert(p,a,L,M,ls[k]):Insert(p,a,M+1,R,rs[k]);
	}
	int Max(int l,int r,int L,int R,int k){
		if(!k)return 0;
		if(l<=L&&R<=r)return mx[k];
		if(r<=M)return Max(l,r,L,M,ls[k]);
		if(l >M)return Max(l,r,M+1,R,rs[k]);
		return std::max(Max(l,r,L,M,ls[k]),Max(l,r,M+1,R,rs[k]));
	}
}t;
int main(){
	int l,r,m;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",a+i),a[i]+=n-i+1;
	a[n+1]=INF;
	for(int i=1;i<=n;i++){
	  for(l=0,r=mx;l<r;)m=l+r+1>>1,a[b[m]]<=a[i]?l=m:r=m-1;
	  dp[i]=l+1,b[l+1]=i;
	  if(dp[i]>mx)mx=dp[i];
	  if(i<n)ans=std::max(ans,dp[i]+1);
	}
	ans=std::max(ans,mx);
	for(int i=0;i<=mx;i++)b[i]=0;
	b[0]=n+1;
	for(int i=n;i;i--){
	  for(l=0,r=mx;l<r;)m=l+r+1>>1,a[b[m]]>=a[i]?l=m:r=m-1;
	  b[l+1]=i;
	  if(i>1)ans=std::max(ans,l+2);
	  t.Insert(a[i],l+1,1,INF,rt);
	  if(i>2)ans=std::max(ans,dp[i-2]+t.Max(a[i-2]-1,INF,1,INF,rt)+1);
	}
	printf("%d\n",n-ans);
	return 0;
}