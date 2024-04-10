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

const int N=3e4+5;
int t,n,k,a[N][4],b[N];

vector<int> ans;

inline int query(int x,int y,int z)
{
	printf("? %d %d %d\n",x,y,z);
	fflush(stdout);
	return !read();
}

signed main()
{
	t=read();
	while(t--)
	{
		ans.clear();
		n=read();k=0;
		for(int i=1;i<=n/3;++i)
			a[i][1]=++k,a[i][2]=++k,a[i][3]=++k;
		for(int i=1;i<=n/3;++i)
			b[i]=query(a[i][1],a[i][2],a[i][3]);
		int ps0=-1,ps1=-1,p0=-1,p1=-1;
		for(int i=1;i<=n/3;++i)
		{
			if(b[i]==0) ps0=i;
			if(b[i]==1) ps1=i;
		}
		int flag=0;
		for(int i=1;i<=3;++i)
			flag|=query(a[ps0][1],a[ps0][2],a[ps1][i]);
		if(flag)
		{
			flag=0;
			for(int i=1;i<=3;++i)
				flag|=query(a[ps0][1],a[ps0][3],a[ps1][i]);
			if(!flag) p0=a[ps0][1],p1=a[ps0][2];
			else p1=a[ps0][1],p0=a[ps0][2];
		}
		else
		{
			p0=a[ps0][1];
			flag=1;
			for(int i=1;i<=3&&flag;++i)
				for(int j=i+1;j<=3&&flag;++j)
					if(query(p0,a[ps1][i],a[ps1][j]))
					{
						p1=a[ps1][i];
						flag=0;
					}
		}
		ans.push_back(p1);
		for(int i=1;i<=n/3;++i)
		{
			int qwq=0;
			for(int j=1;j<=3;++j)
				if(a[i][j]==p0||a[i][j]==p1)
					qwq=1;
			if(qwq)
			{
				for(int j=1;j<=3;++j)
					if(a[i][j]!=p0&&a[i][j]!=p1&&query(p0,p1,a[i][j]))
						ans.push_back(a[i][j]);
			}
			else if(b[i]==0)
			{
				int t1=query(p1,a[i][1],a[i][2]);
				int t2=query(p1,a[i][2],a[i][3]);
				if(t1&&t2) ans.push_back(a[i][2]);
				else if(t1) ans.push_back(a[i][1]);
				else if(t2) ans.push_back(a[i][3]);
			}
			else
			{
				int t1=query(p0,a[i][1],a[i][2]);
				int t2=query(p0,a[i][2],a[i][3]);
				if(!t1&&!t2)
				{
					ans.push_back(a[i][1]);
					ans.push_back(a[i][3]);
				}
				else if(!t1)
				{
					ans.push_back(a[i][2]);
					ans.push_back(a[i][3]);
				}
				else if(!t2)
				{
					ans.push_back(a[i][1]);
					ans.push_back(a[i][2]);
				}
				else
				{
					ans.push_back(a[i][1]);
					ans.push_back(a[i][2]);
					ans.push_back(a[i][3]);
				}
			}
		}
		printf("! %d ",ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%d ",ans[i]);
		puts("");
		fflush(stdout);
	}
	return 0;
}