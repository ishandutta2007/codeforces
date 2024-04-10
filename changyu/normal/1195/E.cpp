#include<cstdio>
#define int long long
#define min(a,b)a<b?a:b
const int N=3001,INF=1e9;
int n,m,k,d,a[N][N],b[N][N],t[N*N],q[N],l,r,ans;
inline void Init(){
	int x,y,z;
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&d);
	scanf("%I64d%I64d%I64d%I64d",t,&x,&y,&z);
	for(int i=1;i<n*m;i++)t[i]=(t[i-1]*x+y)%z;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
		a[i][j]=t[(i-1)*m+j-1];
}
signed main()
{
	Init();
	for(int i=1;i<=n;i++)
	{
	  l=0,r=-1;
	  for(int j=1;j<=m;j++){
		for(;l<=r&&a[i][q[r]]>=a[i][j];r--);
		q[++r]=j;
		for(;l<=r&&q[l]<=j-d;l++);
		if(j>=d)b[i][j]=a[i][q[l]];
	  }
	}
	for(int j=d;j<=m;j++){
	  l=0,r=-1;
	  for(int i=1;i<=n;i++){
		for(;l<=r&&b[q[r]][j]>=b[i][j];r--);
		q[++r]=i;
		for(;l<=r&&q[l]<=i-k;l++);
		if(i>=k)ans=ans+b[q[l]][j];
	  }
	}printf("%I64d\n",ans);
	return 0;
}