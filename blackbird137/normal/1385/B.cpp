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

const int N=55;
int t,n,a;

map<int,bool> mp;

int main()
{
	t=read();
	while(t--)
	{
		mp.clear();
		n=read();
		for(int i=1;i<=n*2;++i)
		{
			a=read();
			if(mp[a]==0)
			{
				mp[a]=1;
				printf("%d ",a);
			}
		}
		printf("\n");
	}
	return 0;
}