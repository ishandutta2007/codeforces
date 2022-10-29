#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int>pii;
#define SIZE 2000000
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	void init()
	{
		for(int i=0;i<SIZE;i++)
		{
			par[i]=i;
			ran[i]=0;
		}
	}
	int find(int a)
	{
		if(a==par[a])return a;
		else return par[a]=find(par[a]);
	}
	void unite(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(ran[a]>ran[b])
		{
			par[b]=a;
		}
		else
		{
			par[a]=b;
		}
		if(ran[a]==ran[b])ran[b]++;
	}
};
unionfind uf;
int map[1006][1006];
int dat[1006][1006];
void dfs(int x,int y,int c)
{
	if(dat[x][y]!=0)return;
	dat[x][y]=c;
	for(int i=-1;i<=1;i++)for(int j=-1;j<=1;j++)if(map[x+i][y+j])dfs(x+i,y+j,c);
}
int main()
{
	int mx,my,query;
	scanf("%d%d%d",&mx,&my,&query);
	for(int i=5;i<=my+3;i++)map[2][i]=1;
	for(int i=2;i<=my;i++)map[mx+3][i]=1;
	for(int i=5;i<=mx+3;i++)map[i][2]=1;
	for(int i=2;i<=mx;i++)map[i][my+3]=1;
	for(int i=3;i<=mx+2;i++)
	{
		for(int j=3;j<=my+2;j++)
		{
			char z;
			scanf(" %c",&z);
			if(z=='#')map[i][j]=1;
		}
	}
	int pt=1;
	for(int i=0;i<=mx+5;i++)
	{
		for(int j=0;j<=my+5;j++)
		{
			if(map[i][j]!=0&&dat[i][j]==0)dfs(i,j,pt++);
		}
	}
	set<pii>se;
	for(int i=0;i<=mx+5;i++)
	{
		for(int j=0;j<=my+5;j++)
		{
			if(map[i][j]==0)continue;
			for(int x=-2;x<=2;x++)
			{
				for(int y=-2;y<=2;y++)
				{
					if(map[i+x][j+y]!=0&&dat[i][j]!=dat[i+x][j+y])
					{
						se.insert(make_pair(dat[i][j],dat[i+x][j+y]));
					}
				}
			}
		}
	}
	/*for(int i=0;i<=mx+6;i++)
	{
		for(int j=0;j<=my+6;j++)
		{
			printf("%c",'A'+dat[i][j]);
		}
		printf("\n");
	}*/
	int st=dat[2][my+3],go=dat[mx+3][2];
	uf.init();
	for(int p=0;p<query;p++)
	{
		int n;
		scanf("%d",&n);
		vector<pii>vec;
		for(int i=0;i<n;i++)
		{
			int za,zb;
			scanf("%d%d",&za,&zb);
			za+=2,zb+=2;
			dat[za][zb]=pt++;
			map[za][zb]=1;
			vec.push_back(make_pair(za,zb));
		}
		vector<int>lis;
		for(int i=0;i<n;i++)
		{
			int nx=vec[i].first,ny=vec[i].second;
			for(int x=-1;x<=1;x++)
			{
				for(int y=-1;y<=1;y++)
				{
					if(map[nx+x][ny+y])
					{
						uf.unite(dat[nx][ny],dat[nx+x][ny+y]);
						lis.push_back(dat[nx+x][ny+y]);
					}
				}
			}
		}
		lis.push_back(st);
		lis.push_back(go);
		if(uf.find(st)==uf.find(go))
		{
			goto l01;
		}
		for(int i=0;i<n;i++)
		{
			int nx=vec[i].first,ny=vec[i].second;
			if(uf.find(dat[nx][ny])!=uf.find(st)&&uf.find(dat[nx][ny])!=uf.find(go))continue;
			for(int x=-2;x<=2;x++)
			{
				for(int y=-2;y<=2;y++)
				{
					if(map[nx+x][ny+y])
					{
						if((uf.find(dat[nx][ny])==uf.find(st)&&uf.find(dat[nx+x][ny+y])==uf.find(go))||(uf.find(dat[nx][ny])==uf.find(go)&&uf.find(dat[nx+x][ny+y])==uf.find(st)))
						{
							goto l01;
						}
					}
				}
			}
		}
		for(int i=0;i<lis.size();i++)
		{
			for(int j=0;j<lis.size();j++)
			{
				if((uf.find(lis[i])==uf.find(st)&&uf.find(lis[j])==uf.find(go))||uf.find(lis[i])==uf.find(go)&&uf.find(lis[j])==uf.find(st))
				{
					if(se.find(make_pair(lis[i],lis[j]))!=se.end())goto l01;
				}
			}
		}
		printf("YES\n");
		if(false)
		{
l01:;
			printf("NO\n");
		}
		for(int i=0;i<lis.size();i++)
		{
			uf.par[lis[i]]=lis[i];
			uf.ran[lis[i]]=0;
		}
		for(int i=0;i<vec.size();i++)
		{
			int x=vec[i].first,y=vec[i].second;
			uf.par[dat[x][y]]=dat[x][y];
			uf.ran[dat[x][y]]=0;
			dat[x][y]=0;
			map[x][y]=0;
		}
		fflush(stdout);
	}
}