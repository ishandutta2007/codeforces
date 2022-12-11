#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],u[MN+5],cnt;
vector<int> v[MN+5];
int main()
{
	int n=read(),i,j,s,s1=0,s2=0,u1=0,u2=0;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)if(!u[i])
	{
		for(++cnt,j=i;!u[j];u[j]=1,j=a[j])v[cnt].push_back(j);
		s=v[cnt].size();
		if(s==1)s1=cnt;if(s==2)s2=cnt;
		u1|=s&1;u2|=~s&1;
	}
	if(!s1&&(u1||u2&&!s2))return 0*puts("NO");
	puts("YES");
	for(i=1;i<=cnt;++i)
		if(s1)for(j=0;j<v[i].size();++j){if(i!=s1)printf("%d %d\n",v[i][j],v[s1][0]);}
		else if(i!=s2)for(j=0;j<v[i].size();++j)printf("%d %d\n",v[i][j],v[s2][j&1]);
	if(!s1)printf("%d %d\n",v[s2][0],v[s2][1]);
}