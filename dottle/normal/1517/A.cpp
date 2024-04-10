#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
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
int n,cnt;
signed main()
{
	int T=read();
	while(T--)
	{
		cnt=0;
		n=read();
		if(n%2050!=0)
		{
			printf("-1\n");continue;
		}
		for(int i=15;i>=0;i--)
		{
			int sum=2050*pow(10,i);
			cnt+=(n/sum);
			n=(n%sum);
			if(n<2050)break;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}