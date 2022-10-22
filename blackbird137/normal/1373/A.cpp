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

int t,a,b,c;

int main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();c=read();
		if(a>=c) printf("-1 ");
		else printf("%d ",1);
		if((c/(b+0.0))<a) printf("%d\n",b);
		else printf("-1\n");
	}
	return 0;
}