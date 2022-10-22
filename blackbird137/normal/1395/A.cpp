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

int t,a,b,c,d;

int main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();c=read();d=read();
		int sum=0;
		if(a%2==0) sum++;
		if(b%2==0) sum++;
		if(c%2==0) sum++;
		if(d%2==0) sum++;
		if(sum>=3)
			printf("Yes\n");
		else if(a>=1&&b>=1&&c>=1)
		{
			a--;b--;c--;
			d+=3;
			sum=0;
			if(a%2==0) sum++;
			if(b%2==0) sum++;
			if(c%2==0) sum++;
			if(d%2==0) sum++;
			if(sum>=3)
				printf("Yes\n");
			else printf("No\n");
		}
		else printf("No\n");
	}
	return 0;
}