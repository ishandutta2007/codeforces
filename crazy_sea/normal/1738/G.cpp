#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=2e3+10;
struct node{
	int x,y;
}p;
vector<node> v[N];
int w[N],t[N][N],n;
void work(int id)
{
	p=v[id][w[id]];
	t[p.x][p.y]=1;
}
bool cmp(node a,node b,int c)
{
	return min(a.x,a.y)+c>min(b.x,b.y);
}
bool chk(int id)
{
	if(w[id]==-1) return 1;
	if(w[id]>=v[id].size()) return 0;
	if(w[id-1]>=0&&cmp(v[id-1][w[id-1]],v[id][w[id]],(id<=n))) return 1;
	if(w[id+1]>=0&&cmp(v[id+1][w[id+1]],v[id][w[id]],(id>=n))) return 1;
	return 0;
}
bool chk2(int id)
{
	return w[id]>=v[id].size();
}
int k;
bool construct()
{
	for(int i=0;i<=2*n;i++) w[i]=-1;
	k=n-k+1;
	for(int i=k;i;i--)
	{
		while(chk(n))
			w[n]++;
		if(chk2(n)) return 1;
		work(n);
		for(int j=1;j<i;j++)
		{
			while(chk(n-j)) w[n-j]++;
			while(chk(n+j)) w[n+j]++;
			if(chk2(n-j)) return 1;
			if(chk2(n+j)) return 1;
			work(n-j),work(n+j);
		}
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=n;j++)
			printf("%d",!t[i][j]);
	return 0;
}
char s[N];
int T;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			for(int j=1;j<=n;j++)
			{
				if(s[j-1]=='1') v[i-j+n].push_back((node){i,j});
			}
		}
		if(construct()) printf("No\n");
		for(int i=1;i<=2*n;i++) v[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				t[i][j]=0;
	}
}