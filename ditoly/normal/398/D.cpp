#include<cstdio>
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
#define MN 50000
#define MM 400000
#define K 500
#define mp(x,y) make_pair(x,y)
int a[MN+5],x[MM+5],y[MM+5],ans[MN+5];
char t[MM+5];
map<int,int> mp[MN+5];
vector< pair<int,int> > v[MN+5],V[MN+5];
void solve(int x,int y,int z)
{
	if(v[x].size()>K)
	{
		if(a[y])z?++ans[x]:--ans[x];
		for(int i=0;i<V[y].size();++i)if(V[y][i].first==x)V[y][i].second=z;
	}
	else for(int i=0;i<v[x].size();++i)if(v[x][i].first==y)v[x][i].second=z;
}
int main()
{
	int n,m,q,i,j;
	n=read();m=read();q=read();
	for(i=read();i--;)a[read()]=1;
	for(i=1;i<=m;++i)t[i]='A',x[i]=read(),y[i]=read();
	for(;i<=q+m;++i)
	{
		do t[i]=getchar();while(t[i]<'A'||t[i]>'Z');
		x[i]=read();if(t[i]=='A'||t[i]=='D')y[i]=read();
	}
	for(i=1;i<=q+m;++i)if(t[i]=='A'&&!mp[x[i]][y[i]])
		mp[x[i]][y[i]]=mp[y[i]][x[i]]=1,v[x[i]].push_back(mp(y[i],0)),v[y[i]].push_back(mp(x[i],0));
	for(i=1;i<=n;++i)if(v[i].size()>K)for(j=0;j<v[i].size();++j)V[v[i][j].first].push_back(mp(i,0));
	for(i=1;i<=q+m;++i)
	{
		if(t[i]=='O')for(a[x[i]]=1,j=0;j<V[x[i]].size();++j)
			if(V[x[i]][j].second)++ans[V[x[i]][j].first];
		if(t[i]=='F')for(a[x[i]]=0,j=0;j<V[x[i]].size();++j)
			if(V[x[i]][j].second)--ans[V[x[i]][j].first];
		if(t[i]=='A')solve(x[i],y[i],1),solve(y[i],x[i],1);
		if(t[i]=='D')solve(x[i],y[i],0),solve(y[i],x[i],0);
		if(t[i]=='C')
			if(v[x[i]].size()>K)printf("%d\n",ans[x[i]]);
			else
			{
				for(j=0;j<v[x[i]].size();++j)ans[x[i]]+=a[v[x[i]][j].first]*v[x[i]][j].second;
				printf("%d\n",ans[x[i]]);ans[x[i]]=0;
			}
	}
}