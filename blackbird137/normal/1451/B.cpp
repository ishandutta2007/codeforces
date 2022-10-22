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

const int N=105;
int t,n,q,pre[N][2],suc[N][2];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();q=read();
		scanf("%s",s+1);
		memset(pre,0,sizeof(pre));
		memset(suc,0,sizeof(suc));
		for(int i=1;i<=n;++i)
		{
			pre[i][0]=pre[i-1][0]+(s[i]=='0');
			pre[i][1]=pre[i-1][1]+(s[i]=='1');
		}
		for(int i=n;i>=1;--i)
		{
			suc[i][0]=suc[i+1][0]+(s[i]=='0');
			suc[i][1]=suc[i+1][1]+(s[i]=='1');
		}
		while(q--)
		{
			int l=read(),r=read(),fl=0;
			if(pre[l-1][s[l]-'0']!=0) fl=1;
			if(suc[r+1][s[r]-'0']!=0) fl=1;
			printf("%s\n",fl?"YES":"NO");
		}
	}
	return 0;
}