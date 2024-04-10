#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 100000
#define MOD 1000000007
int x[MN+5],y[MN+5],c[MN*2+5],cn,f[MN*2+5],s[MN*2+5],S[MN*2+5],p[MN*2+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
int main()
{
	int n=read(),i,ans=1;
	for(i=1;i<=n;++i)c[2*i-1]=x[i]=read()-1e9-1,c[2*i]=y[i]=read()+1e9;
	sort(c+1,c+2*n+1);cn=unique(c+1,c+2*n+1)-c-1;
	for(i=1;i<=n;++i)
	{
		x[i]=lower_bound(c+1,c+cn+1,x[i])-c;
		y[i]=lower_bound(c+1,c+cn+1,y[i])-c;
		if(gf(x[i])!=gf(y[i]))f[gf(x[i])]=gf(y[i]);
	}
	for(i=1;i<=n;++i)++s[gf(x[i])];
	for(p[0]=i=1;i<=cn;++i)++S[gf(i)],p[i]=(p[i-1]<<1)%MOD;
	for(i=1;i<=cn;++i)if(!f[i])ans=1LL*ans*(p[S[i]]+MOD-(s[i]<S[i]))%MOD;
	printf("%d",ans);
}