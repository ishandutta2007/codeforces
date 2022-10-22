#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=205;
int t,n;
char mmap[N][N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			scanf("%s",mmap[i]+1);
		if(mmap[1][2]=='0'&&mmap[2][1]=='0')
		{
			if(mmap[n][n-1]=='1'&&mmap[n-1][n]=='1')
				printf("0\n");
			else if(mmap[n][n-1]=='1')
				printf("1\n%lld %lld\n",n-1,n);
			else if(mmap[n-1][n]=='1')
				printf("1\n%lld %lld\n",n,n-1);
			else printf("2\n%lld %lld\n%lld %lld\n",n,n-1,n-1,n);
		}
		else if(mmap[1][2]=='0'&&mmap[2][1]=='1')
		{
			if(mmap[n][n-1]=='1'&&mmap[n-1][n]=='1')
				printf("1\n%lld %lld\n",2,1);
			else if(mmap[n][n-1]=='1')
				printf("2\n%lld %lld\n%lld %lld\n",2,1,n-1,n);
			else if(mmap[n-1][n]=='1')
				printf("2\n%lld %lld\n%lld %lld\n",2,1,n,n-1);
			else printf("1\n%lld %lld\n",1,2);
		}
		else if(mmap[1][2]=='1'&&mmap[2][1]=='0')
		{
			if(mmap[n][n-1]=='1'&&mmap[n-1][n]=='1')
				printf("1\n%lld %lld\n",1,2);
			else if(mmap[n][n-1]=='1')
				printf("2\n%lld %lld\n%lld %lld\n",1,2,n-1,n);
			else if(mmap[n-1][n]=='1')
				printf("2\n%lld %lld\n%lld %lld\n",1,2,n,n-1);
			else printf("1\n%lld %lld\n",2,1);
		}
		else
		{
			if(mmap[n][n-1]=='0'&&mmap[n-1][n]=='0')
				printf("0\n");
			else if(mmap[n][n-1]=='0')
				printf("1\n%lld %lld\n",n-1,n);
			else if(mmap[n-1][n]=='0')
				printf("1\n%lld %lld\n",n,n-1);
			else printf("2\n%lld %lld\n%lld %lld\n",n,n-1,n-1,n);
		}
	}
	return 0;
}