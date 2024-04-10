#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define maxn 100010
using namespace std;
struct node
{
	int b,p;
};
int tot1,tot2,n,c,d;
int a[2][200000];
int lowbit(int x)
{
	return x & (-x);
}
void insert(int t,int x,int k)
{
	if (x==0)return;
	while (x<=maxn)
	{
		a[t][x]=max(a[t][x],k);
		x+=lowbit(x);
	}
}
int get(int t,int x)
{
	int ans=0;
	while (x>0)
	{
		ans=max(a[t][x],ans);
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&c,&d);
	memset(a,0,sizeof(a));
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		char ch;
		scanf("%d%d %c",&x,&y,&ch);
		int tmp=0;
		if (ch=='C')
		{
			if (c>=y)tmp=max(get(0,c-y),get(1,d));
			insert(0,y,x);
		}
		else
		{
			if (d>=y)tmp=max(get(0,c),get(1,d-y));
			insert(1,y,x);
		}
		if (tmp==0)continue;
		ans=max(ans,tmp+x);
	}	
	cout<<ans<<endl;
	return 0;
}