#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=2*1e5+7;
int num[maxn];
int visit[maxn]={0};
int de[maxn];
int ri[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	bool flag=false;
	int c_d=0;
	int c_i=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		visit[num[i]]++;
		if(visit[num[i]]>2)
		{
			flag=true;
		}
		else if(visit[num[i]]==2)
		{
			de[c_d]=num[i];
			c_d++;
		}
		else
		{
			ri[c_i]=num[i];
			c_i++;
		}
	}
	if(flag)
	{
		printf("NO\n");
	}
	else
	{
		sort(ri,ri+c_i,cmp);
		sort(de,de+c_d);
		printf("Yes\n");
		printf("%d\n",c_d);
		for(int i=0;i<c_d-1;i++)
		{
			printf("%d ",de[i]);
		}
		if(c_d>=1)
		printf("%d",de[c_d-1]);
		puts("");
		printf("%d\n",c_i);
		for(int i=0;i<c_i-1;i++)
		{
			printf("%d ",ri[i]);
		}
		printf("%d",ri[c_i-1]);
	}
	return 0;
}