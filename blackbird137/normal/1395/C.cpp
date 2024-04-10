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

const int N=205;
int n,m,a[N],b[N],c[N],ans;

int main()
{
	memset(c,0x7f,sizeof(c));
	n=read();m=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	for(int i=1;i<=m;++i)
		b[i]=read();
	ans=(1<<9)-1;
	for(int i=8;i>=0;--i)
	{
		int flag=1,res=ans^(1<<i);
		for(int j=1;j<=n;++j)
		{
			int flag2=0;
			for(int k=1;k<=m;++k)
				if(((a[j]&b[k])|res)==res)
				{
					flag2=1;
					break;
				}
			if(!flag2)
			{
				flag=0;
				break;
			}
		}
		ans^=flag<<i;
	}
	printf("%d\n",ans);
	return 0;
}