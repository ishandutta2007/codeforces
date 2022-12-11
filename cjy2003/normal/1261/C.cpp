#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
char *mp[1000010];
int *s[1000010],*cnt[1000010];
inline int get(int x,int y,int xx,int yy){return s[xx][yy]-s[x-1][yy]-s[xx][y-1]+s[x-1][y-1];}
bool check(int l)
{
	for(int i=0;i<=n;++i)memset(cnt[i],0,m+1<<2);
	for(int i=l;i<=n-l+1;++i)
		for(int j=l;j<=m-l+1;++j)
			if(get(i-l+1,j-l+1,i+l-1,j+l-1)==0)++cnt[i-l+1][j-l+1],--cnt[i-l+1][j+l],--cnt[i+l][j-l+1],++cnt[i+l][j+l];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cnt[i][j]+=cnt[i][j-1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(!cnt[i][j]&&mp[i][j]=='X')return 0;
	return 1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n+1;++i)mp[i]=new char[m+2],s[i]=new int[m+2],cnt[i]=new int[m+2];
	for(int i=0;i<=n;++i)memset(s[i],0,m+1<<2);
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]=s[i][j-1]+(mp[i][j]=='.');
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]+=s[i-1][j];
	int l=1,r=min(n,m),mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			if(i>=l&&j>=l&&i+l-1<=n&&j+l-1<=m&&get(i-l+1,j-l+1,i+l-1,j+l-1)==0)printf("X");
			else printf(".");
		printf("\n");	
	}
	return 0;
}