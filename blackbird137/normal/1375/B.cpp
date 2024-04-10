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

const int N=305;
int t,n,m,a[N][N],flag;

int main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();flag=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				a[i][j]=read();
		for(int i=1;i<=n&&flag;++i)
			for(int j=1;j<=m&&flag;++j)
			{
				int res=0;
				if(i-1>=1) res++;
				if(j-1>=1) res++;
				if(i+1<=n) res++;
				if(j+1<=m) res++;
				if(a[i][j]<=res) a[i][j]=res;
				else
				{
					printf("NO\n");
					flag=0;break;
				}
			}
		if(!flag) continue;
		printf("YES\n");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				printf("%d ",a[i][j]);
			printf("\n");
		}	
	}
	
		
	return 0;
}