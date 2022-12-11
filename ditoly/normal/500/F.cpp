#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 20000
#define MX 4000
vector< pair<int,int> > v[MN+5];
int l[MN+5],r[MN+5],cnt;
struct data{int f[MX+5];}d[MX*2+5];
inline void operator+=(data&a,pair<int,int> x)
	{for(int i=MX;i>=x.first;--i)a.f[i]=max(a.f[i],a.f[i-x.first]+x.second);}
int main()
{
	int n=read(),p=read(),i,j,k,ans;
	while(n--)i=read(),j=read(),v[read()].push_back(make_pair(i,j));
	for(i=1;i<=MN;i+=p)
	{
		for(j=0;j<p&&i+j<=MN;++j)
		{
			if(j)r[i+j]=r[i+j-1];
			if(v[i+j].size())
			{
				d[++cnt]=d[r[i+j]];r[i+j]=cnt;
				for(k=0;k<v[i+j].size();++k)d[cnt]+=v[i+j][k];
			}
		}
		for(j=1;j<p&&i-j;++j)
		{
			if(j>1)l[i-j]=l[i-j+1];
			if(v[i-j].size())
			{
				d[++cnt]=d[l[i-j]];l[i-j]=cnt;
				for(k=0;k<v[i-j].size();++k)d[cnt]+=v[i-j][k];
			}
		}
	}
	for(n=read();n--;)
	{
		i=read();j=read();ans=0;
		for(k=0;k<=j;++k)
			ans=max(ans,d[i-p+1>0?l[i-p+1]:0].f[k]+d[r[i]].f[j-k]);
		printf("%d\n",ans);
	}
}