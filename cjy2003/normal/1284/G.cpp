#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int T,n,m,id[30][30],tot,cnt0;
char a[30][30],ans[50][50];
namespace dsu
{
	int f[410];
	void init(int t){for(int i=1;i<=t;++i)f[i]=i;}
	int find(int x)
	{
		if(x!=f[x])return f[x]=find(f[x]);
		return x;
	}
	void merge(int x,int y){f[find(x)]=find(y);}
}
bool in[810];
void matroid_intersection(vector<pair<int,int> >E)
{
	static bool mp[810][810],vis[810];
	static int cnt[410],from[810];
	static queue<int>q;
	int sz=E.size();
	while(1)
	{
		dsu::init(tot);
		for(int i=0;i<sz;++i)
			if(in[i])
			{
				++cnt[E[i].first];
				dsu::merge(E[i].first,E[i].second);
			}
		bool flag=0;
		for(int i=0,p1,p2;i<sz;++i)
			if(!in[i])
			{
				p1=dsu::find(E[i].first)!=dsu::find(E[i].second);
				p2=cnt[E[i].first]<2;
				if(p1&&p2)
				{
					flag=1;in[i]=1;
					break;
				}
				if(p1)mp[sz][i]=1;
				if(p2)mp[i][sz+1]=1;
			}
		memset(cnt+1,0,tot<<2);
		if(!flag)
		{
			for(int i=0;i<sz;++i)
				if(in[i])
				{
					dsu::init(tot);
					for(int j=0;j<sz;++j)
						if(in[j]&&i!=j)
						{
							++cnt[E[j].first];
							dsu::merge(E[j].first,E[j].second);
						}
					for(int j=0;j<sz;++j)	
						if(!in[j])
						{
							if(dsu::find(E[j].first)!=dsu::find(E[j].second))mp[i][j]=1;
							if(cnt[E[j].first]<2)mp[j][i]=1;
						}
					memset(cnt+1,0,tot<<2);
				}
			q.push(sz);vis[sz]=1;
			int x;
			while(!q.empty())
			{
				x=q.front();q.pop();
				for(int i=0;i<=sz+1;++i)
					if(mp[x][i]&&!vis[i])vis[i]=1,from[i]=x,q.push(i);
			}
			if(vis[sz+1])
			{
				flag=1;
				x=from[sz+1];
				while(x!=sz)in[x]^=1,x=from[x];
			}
			memset(vis,0,sz+2);
		}
		for(int i=0;i<=sz+1;++i)memset(mp[i],0,sz+2);
		if(!flag)break;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;++j)if(a[i][j]=='O')id[i][j]=++tot,cnt0+=!(i+j&1);
		}
		--cnt0;
		vector<pair<int,int> >E;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if(i+j==2)continue;
				if(j<m&&a[i][j]=='O'&&a[i][j+1]=='O')E.emplace_back(!(i+j&1)?make_pair(id[i][j],id[i][j+1]):make_pair(id[i][j+1],id[i][j]));
				if(i<n&&a[i][j]=='O'&&a[i+1][j]=='O')E.emplace_back(!(i+j&1)?make_pair(id[i][j],id[i+1][j]):make_pair(id[i+1][j],id[i][j]));
			}
		matroid_intersection(E);
		int sz=E.size(),cnt=0;
		for(int i=0;i<sz;++i)if(in[i])++cnt;
		if(cnt!=2*cnt0)printf("NO\n");
		else
		{
			printf("YES\n");
			int bcnt=0;
			dsu::init(tot);
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
				{
					ans[i*2-1][j*2-1]=a[i][j];
					if(i+j==2)continue;
					if(j<m&&a[i][j]=='O'&&a[i][j+1]=='O')
					{
						if(in[bcnt])ans[i*2-1][j*2]='|',dsu::merge(id[i][j],id[i][j+1]);
						++bcnt;
					}
					if(i<n&&a[i][j]=='O'&&a[i+1][j]=='O')
					{
						if(in[bcnt])ans[i*2][j*2-1]='-',dsu::merge(id[i][j],id[i+1][j]);
						++bcnt;
					}
				}
			for(int i=1;i<=n;++i)
				for(int j=1;j<=m;++j)
				{
					if(j<m&&a[i][j]=='O'&&a[i][j+1]=='O'&&dsu::find(id[i][j])!=dsu::find(id[i][j+1]))ans[i*2-1][j*2]='|',dsu::merge(id[i][j],id[i][j+1]);
					if(i<n&&a[i][j]=='O'&&a[i+1][j]=='O'&&dsu::find(id[i][j])!=dsu::find(id[i+1][j]))ans[i*2][j*2-1]='-',dsu::merge(id[i][j],id[i+1][j]);
				}
			for(int i=1;i<=2*n-1;++i)
			{
				for(int j=1;j<=2*m-1;++j)putchar(ans[i][j]?ans[i][j]:' '),ans[i][j]=0;
				putchar('\n');
			}
		}
		tot=0,cnt0=0;
		memset(in,0,sz);
	}
	return 0;
}