#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
using namespace std;
int n;
int a[1100000];
LL leftmin[1100000],leftmax[1100000],rightmin[1100000],rightmax[1100000];
int top,stack[1100000];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	top=0;
	stack[0]=0;
	for(int i=1;i<=n;i++)
	{
		while (top!=0&&a[stack[top]]>=a[i])stack[top--]=0;
		leftmin[i]=stack[top]+1;
		stack[++top]=i;
	}

	top=0;
	stack[0]=0;
	for(int i=1;i<=n;i++)
	{
		while (top!=0&&a[stack[top]]<=a[i])stack[top--]=0;
		leftmax[i]=stack[top]+1;
		stack[++top]=i;
	}


	top=0;
	stack[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while (top!=0&&a[stack[top]]>a[i])stack[top--]=0;
		rightmin[i]=stack[top]-1;
		stack[++top]=i;
	}
 
	top=0;
	stack[0]=n+1;
	for(int i=n;i>=1;i--)
	{
		while (top!=0&&a[stack[top]]<a[i])stack[top--]=0;
		rightmax[i]=stack[top]-1;
		stack[++top]=i;
	}

	LL ans;
	for(int i=1;i<=n;i++)
	{
		LL tmp=((i-leftmax[i]+1)*(rightmax[i]-i+1)-(i-leftmin[i]+1)*(rightmin[i]-i+1));
		ans+=tmp*(LL)(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}