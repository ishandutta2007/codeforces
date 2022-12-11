#include<cstdio>
#define ll long long
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MOD 1000000007
#define MX 1000000
#define MK 20
int f[MX+5][MK+1],t[MX+5],p[MX+5],pn;
inline void add(int&a,int b){a+=b;if(a>=MOD)a-=MOD;}
int query(int r,int n)
{
	int res=1,i,j;
	while(t[n])
	{
		for(i=t[n],j=0;t[n]==i;++j)n/=i;
		res=(ll)res*f[r][j]%MOD;
	}
	return res;
} 
int main()
{
	int T,i,j;
	for(i=f[0][0]=1;i<MK;++i)f[0][i]=2;
	for(i=1;i<=MX;++i)for(j=0;j<MK;++j)add(f[i][j],f[i-1][j]),add(f[i][j+1],f[i][j]);
	for(i=2;i<=MX;++i)
	{
		if(!t[i])t[i]=i,p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j){t[i*p[j]]=p[j];if(i%p[j]==0)break;}
	}
	for(T=read();T--;)i=read(),printf("%d\n",query(i,read()));
}