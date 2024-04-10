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

int t,n,k;

int main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		if((n-(k-1))>=1&&(n-(k-1))%2==1)
		{
			printf("YES\n");
			for(int i=1;i<=k-1;++i)
				printf("1 ");
			printf("%d\n",n-(k-1));
		}
		else if((n-(k-1)*2)>=1&&(n-(k-1)*2)%2==0)
		{
			printf("YES\n");
			for(int i=1;i<=k-1;++i)
				printf("2 ");
			printf("%d\n",n-(k-1)*2);
		}
		else
			printf("NO\n");
	}
	return 0;
}