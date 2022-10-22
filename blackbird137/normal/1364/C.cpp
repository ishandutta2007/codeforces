
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
 
const int N=1e5+5;
int n,a[N],b[N],have,num,now=1;
 
int main()
{
	memset(b,-1,sizeof(b));
	//  b  
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=n;++i)
	{
		if(a[i]>i)
		//  a_i > i  
		{
			printf("-1\n");
			return 0;
		}
		for(;num<=a[i]-1;++num)
		//  num ~ a_i-1  
		{
			if(b[i]==-1)
			//  a_i  b_i  
				b[i]=num;
			else
			{
				while(b[now]!=-1)
				//  i  
					now++;
				//  
				b[now]=num;
			}
		}
		num=a[i];
	}
	for(int i=1;i<=n;++i)
		if(b[i]==-1) printf("%d ",1000000); // 10^6 
		else printf("%d ",b[i]);
	return 0;
}