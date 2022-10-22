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

int t,n,a[105]={0,6,10,14,15};

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n<=30) printf("NO\n");
		else
		{
			printf("YES\n");
			if(n==36) printf("6 10 15 5\n");
			else if(n==40) printf("6 15 14 5\n");
			else if(n==44) printf("6 10 15 13\n");
			else printf("6 10 14 %d\n",n-30);
		}
	}
	return 0;
}