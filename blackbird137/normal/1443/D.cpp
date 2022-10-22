#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define lowbit(x) (x&(-x))
#define lc (x<<1)
#define rc (x<<1|1)

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

inline int Abs(int a){return a>0?a:-a;};
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}

const int N=3e4+5;
int t,n,a[N],now,pos,flag;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		pos=n;flag=1;now=0;
		for(int i=n-1;i>=1;--i)
			if(a[i]<a[i+1]) pos=i;
			else break;
		for(int i=2;i<=pos;++i)
		{
			a[i]-=now;
			if(a[i]<0) flag=0;
			if(a[i]>a[i-1])
				now+=a[i]-a[i-1],a[i]=a[i-1];
			
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}