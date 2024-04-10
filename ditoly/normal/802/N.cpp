#include<cstdio>
#include<cstring>
#define ll long long
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x*f;
}
#define MN 2200
int a[MN+5],b[MN+5],s[MN+5][MN+5];
ll f[MN+5][MN+5];
int main()
{
	int n,k,i,j;int l=0,r=2e9,mid;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=read();
	while(l<=r)
	{
		mid=l+(r-l>>1);
		memset(f,40,sizeof(f));
		f[0][0]=s[0][0]=0;
		for(i=0;i<=n;++i)for(j=i;j<=n;++j)
		{
			if(f[i][j]<f[i+1][j])f[i+1][j]=f[i][j],s[i+1][j]=s[i][j];
			if(f[i][j]<f[i][j+1])f[i][j+1]=f[i][j],s[i][j+1]=s[i][j];
			if(f[i][j]+a[i+1]+b[j+1]-mid<f[i+1][j+1])
				f[i+1][j+1]=f[i][j]+a[i+1]+b[j+1]-mid,s[i+1][j+1]=s[i][j]+1;
		}
		if(s[n][n]==k)return 0*printf("%I64d",f[n][n]+1LL*k*mid);
		if(s[n][n]<k)l=mid+1;else r=mid-1;
	}
}