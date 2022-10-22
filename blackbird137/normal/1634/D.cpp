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
#include<assert.h>

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

const int N=1e3+5;
int t,n,a[N];

inline int query(int x,int y,int z)
{
	
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);return read();
}

inline void Ans(int x,int y)
{
	
	printf("! %d %d\n",x,y);
	fflush(stdout);
}

inline int find(int x,int y,int z)
{
	for(int i=1;i<=n;++i)
		if(i!=x&&i!=y&&i!=z)
			return i;
	return -1;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		int mx=-1e9,ps=-1,fl=1,ls=-1;
		for(int i=3;i<=n;++i)
		{
			int tmp=query(1,2,i);
			if(tmp>mx)
				mx=tmp,ps=i;
		}
		int A=ps,qwq=-1e9,ttt=mx;
		mx=-1e9,ps=-1,fl=1,ls=-1;
		for(int i=2;i<=n;++i)
			if(i!=A)
			{
				int tmp=query(1,A,i);
				if(tmp>mx)
					mx=tmp,ps=i;
				if(i!=2)
					qwq=max(qwq,tmp);
			}
		if(ps==2&&qwq<ttt)
		{
			int tmp=query(2,A,find(1,2,A));
			if(tmp<mx) Ans(1,2);
			else Ans(2,A);
			continue;
		}
		if(query(A,ps,find(1,A,ps))<mx)
		{
			Ans(1,A);
			continue;
		}
		Ans(A,ps);
	}
	return 0;
}