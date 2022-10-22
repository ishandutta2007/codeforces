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

int t,n;

bool check(int x);

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n==1)
			printf("FastestFinger\n");
		else if(n==2)
			printf("Ashishgup\n");
		else if(n%2==1)
			printf("Ashishgup\n");
		else
		{
			int tmp=n,sum=0;
			while(tmp%2==0) tmp/=2,sum++;
			if(tmp!=1&&(sum>=2||(sum==1&&!check(tmp)))) printf("Ashishgup\n");
			else printf("FastestFinger\n");
		}
A:;
	}
	return 0;
} 

bool check(int x)
{
	if(x==2) return 1;
	for(int i=2;i<=sqrt(x);++i)
		if(x%i==0)
			return 0;
	return 1;
}