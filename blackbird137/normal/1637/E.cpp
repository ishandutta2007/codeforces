#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=3e5+5;
int t,n,m,a[N],k,c[N],tg[N],nm[N],ID1,ID2;

vector<int> hv,sm[N];

struct Node
{
	int x,y;
}b[N];

struct node
{
	int x,y;
	bool operator < (const node &p)const
	{
		return c[sm[ID1][x]]+c[sm[ID2][y]]<c[sm[ID1][p.x]]+c[sm[ID2][p.y]];
	}
};

map<pair<int,int>,bool> qwq,qaq;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();k=0;
		for(int i=1;i<=n;++i)
			a[i]=read(),c[++k]=a[i];
		sort(c+1,c+1+k);
		k=unique(c+1,c+1+k)-c-1;
		for(int i=1;i<=n;++i)
			a[i]=lower_bound(c+1,c+1+k,a[i])-c;
		qwq.clear();
		for(int i=1;i<=m;++i)
		{
			b[i].x=lower_bound(c+1,c+1+k,read())-c;
			b[i].y=lower_bound(c+1,c+1+k,read())-c;
			qwq[mp(b[i].x,b[i].y)]=1;
			qwq[mp(b[i].y,b[i].x)]=1;
		}
		for(int i=1;i<=n;++i)
			nm[a[i]]++;
		for(int i=1;i<=k;++i)
		{
			if(!tg[nm[i]])
				hv.push_back(nm[i]),tg[nm[i]]=1;
			sm[nm[i]].push_back(i);
		}
		int ans=0;
		for(int i=0;i<hv.size();++i)
			sort(sm[hv[i]].begin(),sm[hv[i]].end());
		for(int i=0;i<hv.size();++i)
			for(int j=i+1;j<hv.size();++j)
			{
				priority_queue<node> qu;ID1=hv[i];ID2=hv[j];
				qu.push((node){sm[hv[i]].size()-1,sm[hv[j]].size()-1});
				qaq[mp(sm[hv[i]].size()-1,sm[hv[j]].size()-1)]=1;
				int res=0;qaq.clear();
				while(!qu.empty())
				{
					node u=qu.top();qu.pop();
					if(qwq[mp(sm[hv[i]][u.x],sm[hv[j]][u.y])])
					{
						if(u.x&&!qaq[mp(u.x-1,u.y)])
							qaq[mp(u.x-1,u.y)]=1,qu.push((node){u.x-1,u.y});
						if(u.y&&!qaq[mp(u.x,u.y-1)])
							qaq[mp(u.x,u.y-1)]=1,qu.push((node){u.x,u.y-1});
					}
					else
					{
						res=c[sm[hv[i]][u.x]]+c[sm[hv[j]][u.y]];
						break;
					}
				}
				ans=max(ans,(hv[i]+hv[j])*res);
			}
		for(int i=0;i<hv.size();++i)
		{
			if(sm[hv[i]].size()<=1)
				continue;
			priority_queue<node> qu;ID1=hv[i];ID2=hv[i];
			qu.push((node){sm[hv[i]].size()-2,sm[hv[i]].size()-1});
			qaq[mp(sm[hv[i]].size()-2,sm[hv[i]].size()-1)]=1;
			int res=0;qaq.clear();
			while(!qu.empty())
			{
				node u=qu.top();qu.pop();
				if(qwq[mp(sm[hv[i]][u.x],sm[hv[i]][u.y])])
				{
					if(u.x&&!qaq[mp(u.x-1,u.y)])
						qaq[mp(u.x-1,u.y)]=1,qu.push((node){u.x-1,u.y});
					if(u.y&&u.y-1>u.x&&!qaq[mp(u.x,u.y-1)])
						qaq[mp(u.x,u.y-1)]=1,qu.push((node){u.x,u.y-1});
				}
				else
				{
					res=c[sm[hv[i]][u.x]]+c[sm[hv[i]][u.y]];
					break;
				}
			}
			ans=max(ans,(hv[i]+hv[i])*res);
		}
		write(ans);puts("");
		for(int i=1;i<=n;++i)
			tg[i]=0,nm[i]=0,sm[i].clear();
		hv.clear();
	}
	return 0;
}