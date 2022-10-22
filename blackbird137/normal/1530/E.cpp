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

const int N=1e5+5;
int t,n,nm[30];
char s[N];

signed main()
{
	t=read();
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(nm,0,sizeof(nm));
		for(int i=1;i<=n;++i)
			nm[s[i]-'a'+1]++;
		int f1=0,f2=0;
		for(int i=1;i<=26;++i)
		{
			if(nm[i]==1) f1=1;
			if(nm[i]) f2++;
		}
		if(f1)
		{
			int mn=30;
			for(int i=1;i<=26;++i)
				if(nm[i]==1)
				{
					mn=i;
					break;
				}
			putchar(mn+'a'-1);nm[mn]--;
			for(int i=1;i<=26;++i)
				while(nm[i])
					putchar(i+'a'-1),nm[i]--;
			puts("");
		}
		else if(f2==1)
		{
			for(int i=1;i<=26;++i)
				while(nm[i])
					putchar(i+'a'-1),nm[i]--;
			puts("");
		}
		else
		{
			int mn=30;
			for(int i=1;i<=26;++i)
				if(nm[i])
				{
					mn=i;
					break;
				}
			if(nm[mn]>=n-nm[mn]+3)
			{
				int mn2=30;
				for(int i=mn+1;i<=26;++i)
					if(nm[i])
					{
						mn2=i;
						break;
					}
				putchar(mn+'a'-1);nm[mn]--;
				putchar(mn2+'a'-1);nm[mn2]--;
				
				int mn3=30;
				for(int i=mn2+1;i<=26;++i)
					if(nm[i])
					{
						mn3=i;
						break;
					}
				if(mn3==30)
				{
					while(nm[mn2])
						putchar(mn2+'a'-1),nm[mn2]--;
					while(nm[mn])
						putchar(mn+'a'-1),nm[mn]--;
					puts("");
				}
				else
				{
					while(nm[mn])
					{
						putchar(mn+'a'-1);
						nm[mn]--;
					}
					putchar(mn3+'a'-1);nm[mn3]--;
					for(int i=1;i<=26;++i)
						while(nm[i])
							putchar(i+'a'-1),nm[i]--;
					puts("");
				}
				
			}
			else
			{
				putchar(mn+'a'-1);nm[mn]--;
				putchar(mn+'a'-1);nm[mn]--;
				for(int i=mn+1;i<=26;++i)
					while(nm[i])
					{
						putchar(i+'a'-1);nm[i]--;
						if(nm[mn])
							putchar(mn+'a'-1),nm[mn]--;
					}
				puts("");
			}
		}
	}
	return 0;
}