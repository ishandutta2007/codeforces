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

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e5+5;
int t,n;
char s1[N],s2[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		int flag=1;
		for(int i=1;i<=n;++i)
			if(s1[i]!=s2[i])
				flag=0;
		if(flag)
		{
			puts("0");
			continue;
		}
		flag=1;
		for(int i=1;i<=n;++i)
			if(s1[i]=='1')
				flag=0;
		if(flag)
		{
			puts("-1");
			continue;
		}
		int ans=0,tmp=1e9;
		for(int i=1;i<=n;++i)
			if(s1[i]==s2[i])
				ans++;
		int sum=0;
		for(int i=1;i<=n;++i)
			if(s1[i]==s2[i]&&s1[i]=='1')
				++sum;
		if(sum==ans-sum+1)
			tmp=min(tmp,ans);
		sum=0;
		for(int i=1;i<=n;++i)
			if(s1[i]!=s2[i]&&s1[i]=='1')
				++sum;
		if(sum==n-ans-sum)
			tmp=min(tmp,n-ans);
		if(tmp==1e9) tmp=-1;
		write(tmp);puts("");
	}
	return 0;
}