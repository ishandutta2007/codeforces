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

int t,d,k,s1,s2,fl;

signed main()
{
	t=read();
	while(t--)
	{
		d=read();k=read();
		s1=0,s2=0,fl=0;
		for(int i=0;i*i*2<=d*d;i+=k)
		{
			if((i+k)*(i+k)+i*i>d*d)
				fl=1;
		}
		//printf("%lld %lld\n",s1,s2);
		if(fl) printf("Utkarsh\n");
		else printf("Ashish\n");
	}                     
	return 0;
}