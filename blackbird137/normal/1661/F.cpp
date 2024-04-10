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

#define ll long long
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

inline ll read()
{
	ll ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=4e5+5;
ll n,m,a[N],now,ans;

inline ll query(int n,int k)
{
	ll A=n/k;
	return n*A*2ll+n-k*A*A-A*k;
}

struct Node
{
	int x,l,r;ll v;
	bool operator < (const Node &p)const
	{
		return v<p.v;
	}
};

priority_queue<Node> qu;

inline void insert(int x,int l,int r)
{
	ll val=query(x,l)-query(x,l+1);
	qu.push((Node){x,l,r,val});
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		now+=(a[i]-a[i-1])*1ll*(a[i]-a[i-1]);
		insert(a[i]-a[i-1],1,1);
	}
	m=read();
	while(now>m)
	{
		Node u=qu.top();
		qu.pop();
		ll tmp=u.v;
		ll tmp2=(now-m+tmp-1)/tmp;
		if(tmp2<=u.r-u.l+1)
		{
			ans+=tmp2;
			break;
		}
		else
		{
			ans+=u.r-u.l+1;
			now-=tmp*(u.r-u.l+1);
			if(u.x/(u.r+1)==0)
				continue; 
			if(u.x/u.l!=u.x/(u.l+1))
			{
				int L=u.l+1,R=u.x/(u.x/L);
				if(L==R) insert(u.x,L,R);
				else insert(u.x,L,R-1);
			}
			else insert(u.x,u.r+1,u.r+1);
		}
	}
	write(ans);
	return 0;
}