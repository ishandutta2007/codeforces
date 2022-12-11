#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
struct edge{int nx,c;}e[MN*2+5];
int h[MN+5],en,r[MN+5],cn[MN+5],u[MN+5],cnt;
vector< pair<int,int> > v[MN+5];
vector<int> c[MN+5],f[MN+5];
map<pair<int,int>,int> mp;
inline void ins(int x,int y,int c)
{
	e[++en]=(edge){h[x],c};h[x]=en;++r[x]; 
	e[++en]=(edge){h[y],c};h[y]=en;++r[y];
	v[c].push_back(make_pair(x,y));
}
int gf(int x,int k){return f[x][k]<0?k:f[x][k]=gf(x,f[x][k]);}
#define g(x,y) lower_bound(c[x].begin(),c[x].begin()+cn[x],y)-c[x].begin()
int main()
{
	int n,m,x,y,i,j;
	n=read();m=read();
	for(i=1;i<=m;++i)x=read(),y=read(),ins(x,y,read());
	for(i=1;i<=m;++i)
	{
		for(j=0;j<v[i].size();++j)c[i].push_back(v[i][j].first),c[i].push_back(v[i][j].second);
		sort(c[i].begin(),c[i].end());cn[i]=unique(c[i].begin(),c[i].end())-c[i].begin();
		for(j=0;j<cn[i];++j)f[i].push_back(-1);
		for(j=0;j<v[i].size();++j)
			v[i][j].first=g(i,v[i][j].first),v[i][j].second=g(i,v[i][j].second),
			gf(i,v[i][j].first)!=gf(i,v[i][j].second)?f[i][gf(i,v[i][j].first)]=gf(i,v[i][j].second):0;
	}
	for(m=read();m--;)
	{
		x=read();y=read();
		if(r[x]>r[y]||(r[x]==r[y]&&x>y))swap(x,y);
		if(mp[make_pair(x,y)]){printf("%d\n",mp[make_pair(x,y)]-1);continue;}
		++mp[make_pair(x,y)];++cnt;
		for(i=h[x];i;i=e[i].nx)
		{
			if(u[e[i].c]==cnt)continue;u[e[i].c]=cnt;
			if(j=g(e[i].c,y),j==cn[e[i].c]||c[e[i].c][j]!=y)continue;
			if(gf(e[i].c,g(e[i].c,x))==gf(e[i].c,j))++mp[make_pair(x,y)];
		}
		printf("%d\n",mp[make_pair(x,y)]-1);
	}
}