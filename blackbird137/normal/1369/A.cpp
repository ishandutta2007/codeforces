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

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		if((n-4)/4.0==(double)((n-4)/4))
			printf("YES\n");
			
		else
			printf("NO\n");
	}
	return 0;
}