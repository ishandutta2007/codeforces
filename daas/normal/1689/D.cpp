#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,map[1010][1010],mem[1010][2],pre[1010],suf[1010];
char s[1010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;++j) map[i][j]=(s[j]=='B');
		}
		for(int j=1;j<=m;++j)
		{
			mem[j][0]=mem[j][1]=0;
			for(int i=1;i<=n;++i) if(map[i][j])
			{
				if(!mem[j][0]) mem[j][0]=i;
				mem[j][1]=i;
			}
		}
		int ansx=0,ansy=0,ans=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
		{
			pre[0]=suf[m+1]=-0x3f3f3f3f;
			for(int j=1;j<=m;++j)
			{
				pre[j]=pre[j-1];
				if(mem[j][0])
				{
					pre[j]=max(pre[j],max(abs(mem[j][0]-i),abs(mem[j][1]-i))-j);
				}
			}
			for(int j=m;j>=1;--j)
			{
				suf[j]=suf[j+1];
				if(mem[j][0])
				{
					suf[j]=max(suf[j],max(abs(mem[j][0]-i),abs(mem[j][1]-i))+j);
				}
			}
			for(int j=1;j<=m;++j)
			{
				int val=max(pre[j]+j,suf[j]-j);
				if(val<ans) ansx=i,ansy=j,ans=val;
			}
		}
		printf("%d %d\n",ansx,ansy);
	}
	return 0;
}
//ore no turn,draw!