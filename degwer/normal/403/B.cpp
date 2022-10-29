#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
bool map[100001];
vector<int>pri;
set<int>bp;
int scr(int n)
{
	vector<int>ret;
	for(int i=0;i<pri.size();i++)
	{
		if(pri[i]*pri[i]>n)
		{
			break;
		}
		for(;;)
		{
			if(n%pri[i]!=0)
			{
				break;
			}
			ret.push_back(pri[i]);
			n/=pri[i];
		}
	}
	if(n!=1)
	{
		ret.push_back(n);
	}
	int ans=ret.size();
	for(int i=0;i<ret.size();i++)
	{
		if(bp.find(ret[i])!=bp.end())
		{
			ans-=2;
		}
	}
	return ans;
}
int gcd(int a,int b)
{
	for(;;)
	{
		if(a<b)
		{
			swap(a,b);
		}
		a%=b;
		if(a==0)
		{
			return b;
		}
	}
}
int main()
{
	fill(map+2,map+100001,true);
	for(int i=2;i<=100000;i++)
	{
		if(map[i])
		{
			pri.push_back(i);
			for(int j=i+i;j<=100000;j+=i)
			{
				map[j]=false;
			}
		}
	}
	int num,kin;
	scanf("%d%d",&num,&kin);
	vector<int>vec;
	for(int i=0;i<num;i++)
	{
		int zan;
		scanf("%d",&zan);
		vec.push_back(zan);
	}
	for(int j=0;j<kin;j++)
	{
		int zan;
		scanf("%d",&zan);
		bp.insert(zan);
	}
	for(int i=num-1;i>=0;i--)
	{
		int g=vec[0];
		for(int j=0;j<=i;j++)
		{
			g=gcd(vec[j],g);
		}
		if(scr(g)<0)
		{
			for(int j=0;j<=i;j++)
			{
				vec[j]/=g;
			}
		}
	}
	int ans=0;
	for(int i=0;i<num;i++)
	{
		ans+=scr(vec[i]);
	}
	printf("%d\n",ans);
}