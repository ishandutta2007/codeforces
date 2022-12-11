#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,dep,cnt;
void dfs(int ndep,int op,bool left)
{
	if(ndep==dep)
	{
		if(!op&&left)++cnt;
		return ;
	}
	if(left)
	{
		dfs(ndep+1,op^1,1);
		dfs(ndep+1,0,0);
	}
	else
	{
		dfs(ndep+1,1,1);
		dfs(ndep+1,0,0);
	}
}
int main()
{
	scanf("%d",&n);
	if(n<=2)
	{
		printf("1");
		return 0;
	}
	dep=1;
	while((1<<dep+1)-1<n)++dep;
	if(n&1)dfs(1,1,1);
	else dfs(1,0,0);
//	printf("%d\n",cnt);
	if(cnt+(1<<dep)-1+(1<<dep-2)==n)printf("1");
	else printf("0");
	return 0;
}