#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//#define int long long
const int N = 1e5;

inline int read()
{
	int X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
	if(flag)return X;
	return ~(X-1);
}

inline void write(int X)
{
	if(X<0){X=~(X-1);putchar('-');}
	if(X>9){write(X/10);}
	putchar(X%10+'0');
}

int a[N],T,n,ans,ed,flag=0,b[N];

signed main()
{
	T=read();
	while(T--)
	{
		flag=0;
		ans=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		printf("%d\n",3*n);
		for(int i=0;i<n;i+=2)
		{
			for(int j=1;j<=3;j++)
			{
				printf("2 %d %d\n1 %d %d\n",i+1,i+2,i+1,i+2);
			}
		}
	}
	return 0;
}