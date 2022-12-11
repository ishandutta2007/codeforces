#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m,q;
set<int>e[200020];
bool ok[200020];
int cnt;
void ins(int x,int y)
{
	e[x].insert(y);
	if(y>x&&ok[x])ok[x]=0,--cnt;
}
void del(int x,int y)
{
	e[x].erase(y);
	if(!ok[x]&&(e[x].empty()||*e[x].rbegin()<x))ok[x]=1,++cnt;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)ok[i]=1;
	cnt=n;
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d %d",&x,&y);
		ins(x,y);
		ins(y,x);
	}
	scanf("%d",&q);
	while(q--)
	{
		int c,x,y;
		scanf("%d",&c);
		if(c<=2)scanf("%d %d",&x,&y);
		if(c==1)ins(x,y),ins(y,x);
		else if(c==2)del(x,y),del(y,x);
		else printf("%d\n",cnt);
	}
	return 0;
}