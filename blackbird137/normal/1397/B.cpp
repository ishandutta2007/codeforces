#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int __int128

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

void write(int x)        
{        
    if(x<0){putchar('-');x=-x;}        
    if(x>9)write(x/10);        
    putchar(x%10+'0');        
    return;        
}     

const int N=1e5+5;
int n,a[N],m,ans=1e18;

inline int q_pow(int a,int b);
inline int aabs(int x);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=0;i<=1000000000;++i)
	{
		int tmp=q_pow(i,n-1);
		if(tmp!=-1&&tmp<=a[n])
			m=i;
		else break;
	}
		
	m++;
	for(int i=0;i<=m;++i)
	{
		int res=0;
		for(int j=0;j<=n-1;++j)
			res+=aabs(a[j+1]-q_pow(i,j));
		ans=min(ans,res);
	}
	write(ans);
	return 0;
}

inline int q_pow(int a,int b)
{
	int c=1,ok=0;
	while(b)
	{
		if(b&1)
		{
			if(ok||a*c>=1e18) return -1;
			c=a*c;
		}
		b>>=1;a=a*a;
		if(a>=1e18) ok=1;
	}
	return c;
}

inline int aabs(int x)
{
	if(x<0) return -x;
	return x;
}