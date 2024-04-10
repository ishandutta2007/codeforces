#include <bits/stdc++.h>
using namespace std;
const int maxn=2007;
int num[maxn];
int odd[maxn];
int even[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int c_o=0;
	int c_e=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		if(num[i]%2==0)
		{
			odd[c_o]=num[i];
			c_o++;
		}
		else
		{
			even[c_e]=num[i];
			c_e++;
		}
	}
	sort(odd,odd+c_o);
	sort(even,even+c_e);
	if(abs(c_o-c_e)==1||c_e-c_o==0)
	{
		printf("0\n");
	}
	else
	{
		int sum=0;
		if(c_o==0)
		{
			for(int i=0;i<c_e-1;i++)
			{
				sum+=even[i];
			}
		}
		else if(c_e==0)
		{
			for(int i=0;i<c_o-1;i++)
			{
				sum+=odd[i];
			}
		}
		else
		{
			int s=c_e-c_o;
			if(s>0)
			{
				for(int i=0;i<s-1;i++)
				{
					sum+=even[i];
				}
			}
			else
			{
				s=-s;
				for(int i=0;i<s-1;i++)
				{
					sum=sum+odd[i];
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}