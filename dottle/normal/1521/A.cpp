#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
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

int T,x,y,z,a,b;

signed main()
{
	T=read();
	while(T--)
	{
		a=read(),b=read();
		x=a*b;
		y=a;
		z=a*(b+1);
		if(b==1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%lld %lld %lld\n",x,y,z);
	}
	return 0;
}