#include<cstdio>
#define MN 100001
#define MOD 1000000007
int f[MN+5],r[MN+5];
int C(int n,int m){return 1LL*f[n]*r[m]%MOD*r[n-m]%MOD;}
int inv(int x)
{
	int t=x,y=MOD-3;
	for(;y;t=1LL*t*t%MOD,y>>=1)if(y&1)x=1LL*x*t%MOD;
	return x;
}
int cal(int n,int m,int p)
{
	if(!m)return 1;
	int r=0,i;
	for(i=1;i<=n+1&&i*(p+1)<=m;++i)
		r=(r+1LL*C(m-i*p-1,i-1)*C(n+1,i))%MOD;
	return r;
}
int main()
{
	int n,m,p,i,x=0,y=0;
	for(f[0]=i=1;i<=MN;++i)f[i]=1LL*f[i-1]*i%MOD;
	for(r[i=MN]=inv(f[MN]);i--;)r[i]=1LL*r[i+1]*(i+1)%MOD;
	scanf("%d%d%d",&n,&m,&p);
	printf("%d",1LL*cal(n,m,p)*inv(cal(n,m,0))%MOD);
}//test