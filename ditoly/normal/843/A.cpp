#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 100000
struct data{int x,p;}a[MN+5];
bool cmp(const data&a,const data&b){return a.x<b.x;}
int f[MN+5];
vector<int> v[MN+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
int main()
{
	int n=read(),i,j,ans=0;
	for(i=1;i<=n;++i)a[i].x=read(),a[i].p=i;
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;++i)if(gf(i)!=gf(a[i].p))f[gf(i)]=gf(a[i].p);
	for(i=1;i<=n;++i)v[gf(i)].push_back(i);
	for(i=1;i<=n;++i)if(v[i].size())++ans;
	printf("%d\n",ans);
	for(i=1;i<=n;++i)if(v[i].size())
	{
		printf("%d ",v[i].size());
		for(j=0;j<v[i].size();++j)printf("%d ",v[i][j]);
		puts("");
	}
}