#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cassert>
using namespace std;
int n,m,qnum;
bool mp[500][500],ans[600060];
char s[510];
struct query
{
	int x,y,xx,yy,id;
}tmp;
bitset<500>ok1[500][500],ok2[500][500];
int limx,limy;
void dfs1(int x,int y,int p)
{
	ok1[x][y].set(p);
	if(x>limx&&mp[x-1][y]&&!ok1[x-1][y][p])dfs1(x-1,y,p);
	if(y>limy&&mp[x][y-1]&&!ok1[x][y-1][p])dfs1(x,y-1,p);
}
void dfs2(int x,int y,int p)
{
	ok2[x][y].set(p);
	if(x<limx&&mp[x+1][y]&&!ok2[x+1][y][p])dfs2(x+1,y,p);
	if(y<limy&&mp[x][y+1]&&!ok2[x][y+1][p])dfs2(x,y+1,p);
}
void solve(int l1,int l2,int r1,int r2,int op,vector<query>q)
{
	if(!q.size())return;
	vector<query>q1,q2;
	if(l1==r1)op=1;
	if(l2==r2)op=0;
	if(!op)
	{
		int mid=(l1+r1)>>1;
		limx=l1,limy=l2;
		for(int i=l2;i<=r2;++i)if(mp[mid][i])dfs1(mid,i,i);
		limx=r1,limy=r2;
		for(int i=l2;i<=r2;++i)if(mp[mid+1][i])dfs2(mid+1,i,i);
		for(auto p:q)
		{
			if(p.x<=mid&&p.xx>mid)ans[p.id]=(ok1[p.x][p.y]&ok2[p.xx][p.yy]).count()>0;
			else if(p.x<=mid)q1.emplace_back(p);
			else q2.emplace_back(p);
		}
		for(int i=l1;i<=mid;++i)
			for(int j=l2;j<=r2;++j)
				ok1[i][j].reset();
		for(int i=mid+1;i<=r1;++i)
			for(int j=l2;j<=r2;++j)
				ok2[i][j].reset();
		solve(l1,l2,mid,r2,op^1,q1);
		solve(mid+1,l2,r1,r2,op^1,q2);
	}
	else
	{
		int mid=(l2+r2)>>1;
		limx=l1,limy=l2;
		for(int i=l1;i<=r1;++i)if(mp[i][mid])dfs1(i,mid,i);
		limx=r1,limy=r2;
		for(int i=l1;i<=r1;++i)if(mp[i][mid+1])dfs2(i,mid+1,i);
		for(auto p:q)
		{
			if(p.y<=mid&&p.yy>mid)ans[p.id]=(ok1[p.x][p.y]&ok2[p.xx][p.yy]).count()>0;
			else if(p.y<=mid)q1.emplace_back(p);
			else q2.emplace_back(p);
		}
		for(int i=l1;i<=r1;++i)
			for(int j=l2;j<=mid;++j)
				ok1[i][j].reset();
		for(int i=l1;i<=r1;++i)
			for(int j=mid+1;j<=r2;++j)
				ok2[i][j].reset();
		solve(l1,l2,r1,mid,op^1,q1);
		solve(l1,mid+1,r1,r2,op^1,q2);
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int j=0;j<m;++j)mp[i][j]=s[j]=='.';
	}
	scanf("%d",&qnum);
	vector<query>q;
	for(int i=1;i<=qnum;++i)
	{
		scanf("%d %d %d %d",&tmp.x,&tmp.y,&tmp.xx,&tmp.yy);
		--tmp.x,--tmp.y,--tmp.xx,--tmp.yy;tmp.id=i;
		if(tmp.x==tmp.xx&&tmp.y==tmp.yy)ans[i]=1;
		else q.emplace_back(tmp);
	}
	solve(0,0,n-1,m-1,0,q);
	for(int i=1;i<=qnum;++i)puts(ans[i]?"Yes":"No");
	return 0;
}