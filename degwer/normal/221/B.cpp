#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> hen(int a)
{
	vector<int>ret;
	for(int i=0;i<10;i++)
	{
		ret.push_back(0);
	}
	for(;;)
	{
		if(a==0)
		{
			break;
		}
		ret[a%10]++;
		a/=10;
	}
	return ret;
}
bool han(int a,int b)
{
	vector<int>veca=hen(a),vecb=hen(b);
	for(int i=0;i<10;i++)
	{
		if(veca[i]&&vecb[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int num;
	scanf("%d",&num);
	int ret=0;
	for(int i=1;;i++)
	{
		if(i*i>num)
		{
			break;
		}
		if(num%i==0)
		{
			if(han(i,num))
			{
				ret++;
			}
			if(i*i!=num)
			{
				if(han(num/i,num))
				{
					ret++;
				}
			}
		}
	}
	printf("%d\n",ret);
}