#include<cstdio>
using namespace std;
const int N=2e5+10;
int to[N],t[N],n,ans,T;
void dfs(int l,int r)
{
	if(l>r) return;
	ans++;
	int x=l;
	while(x<r)
	{
		dfs(x+1,to[x]-1);
		x=to[x]+1;
	}
}
char s[N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s);
		for(int i=0,x=0;i<2*n;i++)
		{
			if(s[i]=='(') t[x++]=i;
			else if(s[i]==')') to[t[--x]]=i;
		}
		dfs(0,2*n-1);
		printf("%d\n",ans),ans=0;
	}
}