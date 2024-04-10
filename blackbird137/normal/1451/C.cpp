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
#define QWQ {fl=0;break;}

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

const int N=1e6+5;
int t,n,k,fl,s1[30],s2[30];
char s[N],e[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();k=read();
		scanf("%s",s+1);
		scanf("%s",e+1);
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		for(int i=1;i<=n;++i)
			s1[s[i]-'a'+1]++,s2[e[i]-'a'+1]++;
		fl=1;
		for(int i=1;i<=26;++i)
		{
			if(s1[i]<s2[i]) QWQ
			s1[i]-=s2[i];
			if(i!=26)
			{
				s1[i+1]+=s1[i]/k*k;
				s1[i]%=k;
			}
			if(s1[i]!=0) QWQ;
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}