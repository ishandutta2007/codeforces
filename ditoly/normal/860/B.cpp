#include<cstdio>
#include<map>
using namespace std;
#define ll unsigned long long
#define MN 70000
#define MX 7000000
char s[MN+5][15];
map<ll,int> mp;
int cnt,p[MN+5][9][9],z[MX+5];
int main()
{
	int n,i,j,k,mn,mnl,mnr;ll x;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s[i]);
		for(j=0;j<9;++j)for(x=0,k=j;k<9;++k)
		{
			x=x*11+s[i][k]-'0'+1;
			if(!mp[x])mp[x]=++cnt;
			++z[p[i][j][k]=mp[x]];
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=0;j<9;++j)for(k=j;k<9;++k)--z[p[i][j][k]];
		for(mn=10,j=0;j<9;++j)for(k=j;k<9;++k)
			if(!z[p[i][j][k]]&&k-j<mn)mn=k-j,mnl=j,mnr=k;
		for(j=0;j<9;++j)for(k=j;k<9;++k)++z[p[i][j][k]];
		for(j=mnl;j<=mnr;++j)putchar(s[i][j]);puts("");
	}
}