#include<cstdio>
typedef long long ll;
const ll INF=1e12;
const int N=1e5+3,K=21;
int n,k,a[N],L,R,B[N];ll dp[K][N],S;
inline void Add(int k,int f){
	S-=(ll)B[a[k]]*(B[a[k]]-1)/2;
	B[a[k]]+=f;
	S+=(ll)B[a[k]]*(B[a[k]]-1)/2;
}
void Dp(int j,int l,int r,int s,int t){
	if(l>r)return;
	int m=l+r>>1,f;
	dp[j][m]=INF;
	for(int i=s;i<=t&&i<m;i++){
	  for(;L>i+1;)Add(--L,1);
	  for(;R<m  ;)Add(++R,1);
	  for(;L<i+1;)Add(L++,-1);
	  for(;R>m  ;)Add(R--,-1);
	  if(dp[j-1][i]+S<dp[j][m])
		dp[j][m]=dp[j-1][i]+S,f=i;
	}
	Dp(j,l,m-1,s,f),Dp(j,m+1,r,f,t);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)dp[0][i]=INF;
	L=R=1,B[a[1]]=1,S=0;
	for(int j=1;j<=k;j++)Dp(j,1,n,0,n-1);
	printf("%lld\n",dp[k][n]);
	return 0;
}