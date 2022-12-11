#include<cstdio>
using namespace std;
#define ll long long
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define MK 10
#define MN 60
int a[MN+5],an;
ll f[MK+5][MN+5][1024];
ll cal(int b,ll r)
{
	if(!r)return 0; 
	ll res=0;int v=0;
	for(an=0;r;r/=b)a[++an]=r%b;
	for(int i=an;i;--i)
	{
		for(int j=i==an;j<a[i];++j)v^=1<<j,res+=f[b][i-1][v],v^=1<<j;
		v^=(1<<a[i]);
	}
	if(!v)++res;
	for(int i=an;i--;)for(int j=1;j<b;++j)res+=f[b][i-1][1<<j];
	return res;
}
int main()
{
	int n=read(),i,j,k,b;ll l,r;
	for(i=2;i<=10;++i)
	{
		f[i][0][0]=1;
		for(j=1;j<=MN;++j)for(k=0;k<1<<i;++k)if(f[i][j-1][k])
			for(b=0;b<i;++b)f[i][j][k^(1<<b)]+=f[i][j-1][k];
	}
	while(n--)
	{
		b=read();l=read();r=read();
		printf("%I64d\n",cal(b,r)-cal(b,l-1));
	}
}