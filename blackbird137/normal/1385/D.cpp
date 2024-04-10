#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=2e5+5;
int t,n,ans;
char a[N];

void dfs(int l,int r,int sum,char now);

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",a+1);
		ans=1e9;
		dfs(1,n,0,'a');
		printf("%d\n",ans);
	}
	return 0;
}

void dfs(int l,int r,int sum,char now)
{
	if(l==r)
	{
		if(a[l]==now) ans=min(ans,sum);
		else ans=min(ans,sum+1);
		return;
	}
	int res=0,mid=l+r>>1;
	for(int i=l;i<=mid;++i)
		if(a[i]!=now)
			res++;
	dfs(mid+1,r,sum+res,now+1);
	res=0;
	for(int i=mid+1;i<=r;++i)
		if(a[i]!=now)
			res++;
	dfs(l,mid,sum+res,now+1);
}