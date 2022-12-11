#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MN 75
#define INF 0x3FFFFFFF
char s[MN+5];
vector<int> v[3];
int f[MN+5][MN+5][MN+5][2];
int main()
{
	int n,i,j,k,l,cnt;
	scanf("%d%s",&n,s);
	for(i=0;i<n;++i)
		if(s[i]=='V')v[0].push_back(i);
		else if(s[i]=='K')v[1].push_back(i);
		else v[2].push_back(i);
	for(i=0;i<=v[0].size();++i)for(j=0;j<=v[1].size();++j)for(k=0;k<=v[2].size();++k)if(i||j||k)
	{
		f[i][j][k][0]=f[i][j][k][1]=INF;
		if(i)
		{
			f[i][j][k][1]=min(f[i-1][j][k][0],f[i-1][j][k][1]);
			for(l=0;l<j;++l)if(v[1][l]>v[0][i-1])++f[i][j][k][1];
			for(l=0;l<k;++l)if(v[2][l]>v[0][i-1])++f[i][j][k][1];
		}
		if(j)
		{
			cnt=f[i][j-1][k][0];
			for(l=0;l<i;++l)if(v[0][l]>v[1][j-1])++cnt;
			for(l=0;l<k;++l)if(v[2][l]>v[1][j-1])++cnt;
			f[i][j][k][0]=min(f[i][j][k][0],cnt);
		}
		if(k)
		{
			cnt=min(f[i][j][k-1][0],f[i][j][k-1][1]);
			for(l=0;l<i;++l)if(v[0][l]>v[2][k-1])++cnt;
			for(l=0;l<j;++l)if(v[1][l]>v[2][k-1])++cnt;
			f[i][j][k][0]=min(f[i][j][k][0],cnt);
		}
	}
	printf("%d",min(f[i-1][j-1][k-1][0],f[i-1][j-1][k-1][1]));
}