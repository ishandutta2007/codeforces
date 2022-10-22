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

const int N=2e5+5;
int t,n,m,k,nm[30],vis[N];
char s1[N],s2[N],s3[N];

vector<int> ps[30];

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s1+1);n=strlen(s1+1);
		scanf("%s",s2+1);m=strlen(s2+1);
		for(int i=1;i<=m;++i)
			nm[s2[i]-'A']++;
		for(int i=1;i<=n;++i)
			ps[s1[i]-'A'].push_back(i);
		int flag=1;
		for(int i=0;i<26;++i)
		{
			if(ps[i].size()<nm[i])
			{
				flag=0;
				break;
			}
			int len=ps[i].size();
			for(int j=1;j<=nm[i];++j)
				vis[ps[i][len-j]]=1;
		}
		if(!flag)
			puts("NO");
		else
		{
			k=0;
			for(int i=1;i<=n;++i)
				if(vis[i]) s3[++k]=s1[i];
			if(k!=m)
				puts("NO");
			else
			{
				for(int i=1;i<=m;++i)
					flag&=(s2[i]==s3[i]);
				if(!flag) puts("NO");
				else puts("YES");
			}
		}
		for(int i=0;i<26;++i)
			nm[i]=0,ps[i].clear();
		for(int i=1;i<=n;++i)
			vis[i]=0;
	}
	return 0;
}