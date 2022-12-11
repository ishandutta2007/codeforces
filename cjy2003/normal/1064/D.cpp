#include<cstdio>
#include<deque>
using namespace std;
deque<pair<int,int> >q;
int n,m,x,y,mx,my,sx[2010][2010],sy[2010][2010],fx[4]={1,-1,0,0},fy[4]={0,0,-1,1};
char mapi[2010][2010];
bool bj[2010][2010];
int ans,xx,yy;
void search()
{
	q.push_front(make_pair(x,y));
	ans=1;
	while(!q.empty())
	{
		x=q.front().first;
		y=q.front().second;
		q.pop_front();
	//	printf("%d %d\n",x,y);
		for(int i=0;i<=3;++i)
		{
			xx=x+fx[i];
			yy=y+fy[i];
			if(xx>n||yy>m||!xx||!yy)continue;
			if(mapi[xx][yy]=='*'||bj[xx][yy])continue;
			if(i==2&&!sx[x][y])continue;
			if(i==3&&!sy[x][y])continue;
			bj[xx][yy]=1;
			sx[xx][yy]=sx[x][y],sy[xx][yy]=sy[x][y];
			if(i==2)--sx[xx][yy];
			if(i==3)--sy[xx][yy];
			if(i<=1)q.push_front(make_pair(xx,yy));
			else q.push_back(make_pair(xx,yy));
			++ans;
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%d %d",&x,&y);
	scanf("%d %d",&mx,&my);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf(" %c",&mapi[i][j]);
	sx[x][y]=mx;
	sy[x][y]=my;
	bj[x][y]=1;		
	search();
	printf("%d",ans);
	return 0;
}