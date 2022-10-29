#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define LIMIT 2000000
typedef long long ll;
vector<int>prime;
bool map[LIMIT+1];
void primefind()
{
	fill(map,map+LIMIT+1,true);
	for(int i=2;;i++)
	{
		if(i*i>LIMIT)
		{
			break;
		}
		map[i]=false;
		bool han=true;
		for(int j=0;j<prime.size();j++)
		{
			if(prime[j]*prime[j]>i)
			{
				break;
			}
			if(i%prime[j]==0)
			{
				han=false;
				break;
			}
		}
		if(han)
		{
			prime.push_back(i);
			map[i]=true;
		}
	}
	for(int i=0;i<prime.size();i++)
	{
		for(int j=2;prime[i]*j<=LIMIT;j++)
		{
			map[prime[i]*j]=false;
		}
	}
}
bool m[LIMIT+1];
int main()
{
	primefind();
	for(int i=1;i<=LIMIT;i++)
	{
		vector<int>v;
		int p=i;
		for(;;)
		{
			if(p==0)break;
			v.push_back(p%10);
			p/=10;
		}
		bool f=true;
		for(int j=0;j<v.size();j++)
		{
			if(v[j]!=v[v.size()-1-j])f=false;
		}
		m[i]=f;
	}
	int ca=0,cb=0;
	int maxi=0;
	int za,zb;
	scanf("%d%d",&za,&zb);
	map[1]=false;
	for(int i=1;i<LIMIT;i++)
	{
		//if(m[i])printf("%d\n",i);
		if(map[i])ca++;
		if(m[i])cb++;
		if(zb*ca<=za*cb)maxi=i;
	}
	printf("%d\n",maxi);
}