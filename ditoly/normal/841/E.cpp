#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300
#define MOD 1000000007
map<int,int> mp;
int f[2][MN+5],C[MN+5][MN+5];
int main()
{
	int n=read(),x,i,j,k,ls=0,s=0,p=0,q=1,v=1;
	for(i=0;i<=n;++i)for(C[i][0]=j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
	for(;n--;++mp[x])for(x=read(),i=2;i*i<=x;++i)while(x%(i*i)==0)x/=i*i;
	for(map<int,int>::iterator i=mp.begin();i!=mp.end();++i)
	{
		ls=s;s+=i->second;p^=1;q^=1;
		memset(f[p],0,sizeof(f[p]));
		for(int i=2;i<=s-ls;++i)v=1LL*v*i%MOD;
		if(!ls){f[p][s-1]=1;continue;}
		for(int i=0;i<ls;++i)if(f[q][i])
			for(j=0;j<=i&&j<=s-ls;++j)for(k=0;k<=ls+1-i&&k<=s-ls-j;++k)
				f[p][i-j+s-ls-j-k]=(f[p][i-j+s-ls-j-k]+
					1LL*f[q][i]*C[i][j]%MOD*C[ls+1-i][k]%MOD*C[s-ls-1][j+k-1])%MOD;
	}
	printf("%d",1LL*f[p][0]*v%MOD);
}