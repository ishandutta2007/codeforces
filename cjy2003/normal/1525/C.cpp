#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int T,n,m,x[300030];
char c[300030];
struct node
{
	int x,c,id;
};
vector<node>p[2];
node st[300030];
int tp;
int ans[300030];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&x[i]);
		for(int i=1;i<=n;++i)scanf(" %c",&c[i]);
		for(int i=1;i<=n;++i)p[x[i]&1].emplace_back(node{x[i],c[i]=='L',i});
		for(int i=0;i<=1;++i)
		{
			sort(p[i].begin(),p[i].end(),[&](node x,node y){return x.x<y.x;});
			int sz=p[i].size();
			// for(int j=0;j<sz;++j)printf("%d %d %d\n",p[i][j].x,p[i][j].c,p[i][j].id);
			tp=0;
			for(int j=0;j<sz;++j)
				if(p[i][j].c==0)st[++tp]=p[i][j];
				else if(tp)
				{
					ans[st[tp].id]=ans[p[i][j].id]=(p[i][j].x-st[tp].x)/2;
					--tp;
				}
			node last={0,0,0};
			for(int j=sz-1;j>=0;--j)
				if(p[i][j].c==0&&!ans[p[i][j].id])
				{
					if(!last.id)last=p[i][j];
					else ans[last.id]=ans[p[i][j].id]=(m-last.x+m-p[i][j].x)/2,last.id=0;
				}
			node lastr=last;
			last.id=0;
			for(int j=0;j<sz;++j)
				if(p[i][j].c==1&&!ans[p[i][j].id])
				{
					if(!last.id)last=p[i][j];
					else ans[last.id]=ans[p[i][j].id]=(last.x+p[i][j].x)/2,last.id=0;
				}
			node lastl=last;
			// printf("lastl %d %d %d\n",lastl.x,lastl.c,lastl.id);
			// printf("lastr %d %d %d\n",lastr.x,lastr.c,lastr.id);
			if(lastl.id&&lastr.id)ans[lastl.id]=ans[lastr.id]=(m+m-lastr.x+lastl.x)/2;
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]?ans[i]:-1),ans[i]=0;
		printf("\n");
		p[0].clear(),p[1].clear();
	}
	return 0;
}