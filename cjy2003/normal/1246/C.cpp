#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
int n,m,cntr[2020][2020],cntd[2020][2020],ar[2020][2020],ad[2020][2020],sr[2020],sd[2020];
char mp[2020][2020];
int main()
{
	scanf("%d %d",&n,&m);
	if(n==1&&m==1)return printf("1"),0;
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=m;j;--j)cntr[i][j]=cntr[i][j+1]+(mp[i][j]=='R');
	for(int j=1;j<=m;++j)
		for(int i=n;i;--i)cntd[i][j]=cntd[i+1][j]+(mp[i][j]=='R');
	sr[1]=sd[1]=1;
	add(ar[1][m+1-cntr[1][1]],mod-1);
	add(ad[n+1-cntd[1][1]][1],mod-1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			add(sr[i],ar[i][j]);
			add(sd[j],ad[i][j]);
			if(i>1)
			{
				add(ar[i][j+1],sd[j]);
				add(ar[i][m+1-cntr[i][j+1]],mod-sd[j]);
			}
			if(j>1)
			{
				add(ad[i+1][j],sr[i]);
				add(ad[n+1-cntd[i+1][j]][j],mod-sr[i]);
			}
		}
	printf("%d",pl(sr[n],sd[m]));
	return 0;
}