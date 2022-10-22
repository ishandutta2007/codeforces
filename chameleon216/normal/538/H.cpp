#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100,Inf=0x3f3f3f3f;
int Lt,Rt,N,M,L[MX],R[MX],B[MX];
vector<int> G[MX];

void Fail(){printf("IMPOSSIBLE\n"),exit(0);}
void dfs(int x)
{
	for(int y:G[x])
	{
		if(B[x]==B[y])Fail();
		if(!B[y])B[y]=3-B[x],dfs(y);
	}
}
int main()
{
	scanf("%d%d%d%d",&Lt,&Rt,&N,&M);
	int a=Inf,b=-Inf;
	Fr(i,1,N)scanf("%d%d",&L[i],&R[i]),a=min(a,R[i]),b=max(b,L[i]);
	if(a+b<Lt)b=Lt-a;
	if(a+b>Rt)a=Rt-b;
	if(a<0)Fail();
	Fr(i,1,N)
	{
		int p=L[i]<=a&&a<=R[i],q=L[i]<=b&&b<=R[i];
		if(p&&q)continue;
		else if(p)B[i]=1;
		else if(q)B[i]=2;
		else Fail();
	}
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	Fr(i,1,N)if(B[i])dfs(i);
	Fr(i,1,N)if(!B[i])B[i]=1,dfs(i);
	printf("POSSIBLE\n%d %d\n",a,b);
	Fr(i,1,N)printf("%d",B[i]);
	return 0;
}