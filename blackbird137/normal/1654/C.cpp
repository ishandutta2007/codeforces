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
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
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

const int N=2e5+5;
int t,n,w,a[N],all,flag,fl;

map<int,int> s,ok;

void init(int x)
{
	if(fl) return;
	if(s[x]) fl=1;
	if(x==1||ok[x])
		return;
	ok[x]=1;
	init(x/2);init((x+1)/2);
}

inline bool check(int x)
{
	ok.clear();fl=0;
	init(x);
	return fl;
}

void work(int x)
{
	if(!flag)
		return;
	if(!check(x))
	{
		flag=0;
		return;
	}
	if(s[x])
	{
		s[x]--,all--;
		return;
	}
	if(x==1)
	{
		flag=0;
		return;
	}
	work(x/2);
	work((x+1)/2);
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();all=n;
		s.clear();
		w=0;flag=1;
		for(int i=1;i<=n;++i)
		{
			a[i]=read(),w+=a[i];
			s[a[i]]++;
		}
		work(w);
		if(all==0&&flag)
			puts("Yes");
		else puts("No");
	}
	return 0;
}