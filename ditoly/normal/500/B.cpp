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
#define MN 300
int a[MN+5],f[MN+5];
char s[MN+5];
vector<int> v[MN+5],w[MN+5];
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
bool cmp(int x,int y){return a[x]<a[y];}
int main()
{
	int n=read(),i,j;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=i;j<=n;++j)if(s[j]=='1')if(gf(i)!=gf(j))f[gf(i)]=gf(j);
	}
	for(i=1;i<=n;++i)v[gf(i)].push_back(i),w[gf(i)].push_back(i);
	for(i=1;i<=n;++i)
	{
		sort(v[i].begin(),v[i].end());
		sort(w[i].begin(),w[i].end(),cmp);
		for(j=0;j<v[i].size();++j)f[v[i][j]]=a[w[i][j]];
	}
	for(i=1;i<=n;++i)printf("%d ",f[i]);
}