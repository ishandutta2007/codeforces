#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;
int n,a[300010];
char s[10];
int main()
{
	cin>>n;
	int ans=0;
	int now=1;
	int top=0;
	int tag=0;
	for(int i=1;i<=2*n;i++)
	{
		scanf("%s",s);
		int x;
		if(strcmp(s,"add")==0)
		{
			scanf("%d",&x);
			a[++top]=x;
		}
		else
		if (strcmp(s,"remove")==0)
		{
			if(tag==top)tag--,top--,now++;
			else 
			if(a[top]==now)
			{
				top--;
				now++;
			}
			else
			{
				ans++;
				tag=top-1;
				top--;
				now++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}