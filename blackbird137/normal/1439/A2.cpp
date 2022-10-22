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
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs
#define XOR(x,y) (s[x][y]=(s[x][y]=='0'?'1':'0'))

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
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=105;
int t,n,m;
char s[N][N];

struct Node
{
	int x1,y1,x2,y2,x3,y3;
};

vector<Node> ans;

inline void work(int x,int y);
inline void add(int x1,int y1,int x2,int y2,int x3,int y3);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		ans.clear();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n-2;++i)
			for(int j=1;j<=m-2;++j)
				if(s[i][j]=='1')
					add(i,j,i+1,j,i,j+1);
		for(int i=1;i+1<=n-2;i+=2)
			work(i,m-1);
		if(n%2==1)
		{
			if(s[n-2][m-1]=='1'&&s[n-2][m]=='1') add(n-2,m-1,n-2,m,n-1,m-1);
			if(s[n-2][m-1]=='1'&&s[n-2][m]=='0') add(n-2,m-1,n-1,m,n-1,m-1);
			if(s[n-2][m-1]=='0'&&s[n-2][m]=='1') add(n-2,m,n-1,m,n-1,m-1);
		}
		for(int i=1;i+1<=m-2;i+=2)
			work(n-1,i);
		if(m%2==1)
		{
			if(s[n-1][m-2]=='1'&&s[n][m-2]=='1') add(n-1,m-2,n,m-2,n-1,m-1);
			if(s[n-1][m-2]=='1'&&s[n][m-2]=='0') add(n-1,m-2,n,m-1,n-1,m-1);
			if(s[n-1][m-2]=='0'&&s[n][m-2]=='1') add(n,m-2,n,m-1,n-1,m-1);
		}
		work(n-1,m-1);
		printf("%lld\n",ans.size());
		for(int i=0;i<ans.size();++i)
			printf("%lld %lld %lld %lld %lld %lld\n",ans[i].x1,ans[i].y1,ans[i].x2,ans[i].y2,ans[i].x3,ans[i].y3);
	}
	return 0;
}

inline void work(int x,int y)
{
	if(s[x][y]=='1'&&s[x+1][y]=='1'&&s[x][y+1]=='1'&&s[x+1][y+1]=='1')add(x,y,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='0'&&s[x][y+1]=='0'&&s[x+1][y+1]=='0')add(x,y,x+1,y,x,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='1'&&s[x][y+1]=='0'&&s[x+1][y+1]=='0')add(x,y,x+1,y,x+1,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='0'&&s[x][y+1]=='1'&&s[x+1][y+1]=='0')add(x,y,x,y+1,x+1,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='0'&&s[x][y+1]=='0'&&s[x+1][y+1]=='1')add(x+1,y+1,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='1'&&s[x][y+1]=='0'&&s[x+1][y+1]=='0')add(x+1,y+1,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='0'&&s[x][y+1]=='1'&&s[x+1][y+1]=='0')add(x+1,y+1,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='0'&&s[x][y+1]=='0'&&s[x+1][y+1]=='1')add(x+1,y+1,x+1,y,x,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='1'&&s[x][y+1]=='1'&&s[x+1][y+1]=='0')add(x,y,x+1,y,x+1,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='1'&&s[x][y+1]=='0'&&s[x+1][y+1]=='1')add(x,y,x+1,y,x,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='0'&&s[x][y+1]=='1'&&s[x+1][y+1]=='1')add(x,y,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='1'&&s[x][y+1]=='1'&&s[x+1][y+1]=='0')add(x,y,x+1,y,x,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='1'&&s[x][y+1]=='0'&&s[x+1][y+1]=='1')add(x,y,x+1,y,x+1,y+1);
	if(s[x][y]=='1'&&s[x+1][y]=='0'&&s[x][y+1]=='1'&&s[x+1][y+1]=='1')add(x,y,x,y+1,x+1,y+1);
	if(s[x][y]=='0'&&s[x+1][y]=='1'&&s[x][y+1]=='1'&&s[x+1][y+1]=='1')add(x+1,y,x,y+1,x+1,y+1);
}

inline void add(int x1,int y1,int x2,int y2,int x3,int y3)
{
	ans.push_back((Node){x1,y1,x2,y2,x3,y3});
	XOR(x1,y1);XOR(x2,y2);XOR(x3,y3);
}