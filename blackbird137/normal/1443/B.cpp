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

const int N=1e5+5;
int t,n,a,b,ans,ok[N];
char s[N];

vector<pair<int,int> > v;

signed main()
{
	t=read();
	while(t--)
	{
		v.clear();
		a=read();b=read();
		scanf("%s",s+1);
		n=strlen(s+1);
		for(int i=1;i<=n;++i)
			if(s[i]=='1')
			{
				if(s[i-1]!='1') v.push_back(make_pair(i,i));
				else v[v.size()-1].second=i;
			}
		for(int i=1;i<v.size();++i)
			if(a*2>b*(v[i].first-v[i-1].second-1)+a)
				ok[i]=2;
			else ok[i]=1;
		ans=a;
		if(v.size()==0) ans=0;
		for(int i=1;i<v.size();++i)
			if(ok[i]==2) ans+=b*(v[i].first-v[i-1].second-1);
			else ans+=a;
		printf("%lld\n",ans);
	}
	return 0;
}