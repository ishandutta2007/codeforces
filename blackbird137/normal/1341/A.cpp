#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int t,n,a,b,c,d;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		a=read();b=read();c=read();d=read();
		if(n*(a+b)>=(c-d)&&n*(a-b)<=(c+d))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}