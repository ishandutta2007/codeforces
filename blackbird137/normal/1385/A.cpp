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

int t,x,y,z,a,b,c;

int main()
{
	t=read();
	while(t--)
	{
		x=read();y=read();z=read();
		if(x==y&&y==z) printf("YES\n%d %d %d\n",x,y,z);
		else if(x==y&&x>=z) printf("YES\n%d %d %d\n",x,z,z);
		else if(x==z&&x>=y) printf("YES\n%d %d %d\n",y,x,y);
		else if(y==z&&y>=x) printf("YES\n%d %d %d\n",x,x,y);
		else printf("NO\n");
	}
	return 0;
}