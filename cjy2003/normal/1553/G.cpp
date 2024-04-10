#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy 
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	inline void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename T>
	inline void print(T x)
	{
		if(!x){putc('0');return;}
		if(x<0)putc('-'),x=-x;
		static int st[30],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
int n,q,f[1000010],p[1000010],pnum,a[150010];
bool vis[1000010];
vector<int>d[1000010];
map<pair<int,int>,bool>mp;
void init()
{
	for(int i=1;i<=1000001;++i)f[i]=i;
	for(int i=2;i<=1000001;++i)
	{
		if(!vis[i])p[++pnum]=i,d[i].emplace_back(i);
		for(int j=1;j<=pnum&&p[j]*i<=1000001;++j)
		{
			vis[p[j]*i]=1;
			d[p[j]*i]=d[i];
			if(i%p[j]==0)break;
			else d[p[j]*i].emplace_back(p[j]);
		}
	}
}
int find(int x)
{
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
int solve(int x,int y)
{
	if(x==y)return 0;
	if(mp[make_pair(x,y)]||mp[make_pair(y,x)])return 1;
	return 2;
}
int main()
{
	init();
	n=read(),q=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		int rt=find(d[a[i]][0]);
		for(auto x:d[a[i]])f[find(x)]=rt;
	}
	for(int i=1;i<=n;++i)
	{
		int rt=find(d[a[i]][0]);
		for(auto x:d[a[i]+1])mp[make_pair(rt,find(x))]=1;
		for(auto x:d[a[i]+1])
			for(auto y:d[a[i]+1])
				mp[make_pair(find(x),find(y))]=1;
	}
	while(q--)print(solve(find(d[a[read()]][0]),find(d[a[read()]][0]))),putc('\n');
	flush();
	return 0;
}