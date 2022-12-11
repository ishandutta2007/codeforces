#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<random>
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
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename o>
	inline void print(o x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
mt19937 myrand(time(0)+(unsigned long long)(new char));
namespace treap
{
	int ch[10000000][2],w[10000000],siz[10000000],tot;
	void pushup(int x){siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;}
	void print(int x)
	{
		if(ch[x][0])print(ch[x][0]);
		printf("%d ",w[x]);
		if(ch[x][1])print(ch[x][1]);
	}
	void build(int &p,int l,int r,vector<int>&s)
	{
		if(l>r)return;
		int mid=(l+r)>>1;
		p=++tot;w[p]=s[mid];siz[p]=r-l+1;
		build(ch[p][0],l,mid-1,s);
		build(ch[p][1],mid+1,r,s);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		if(myrand()%(siz[x]+siz[y])<siz[x])
		{
			ch[x][1]=merge(ch[x][1],y);
			pushup(x);
			return x;
		}
		else
		{
			ch[y][0]=merge(x,ch[y][0]);
			pushup(y);
			return y;
		}
	}
	pair<int,int>split_by_value(int p,int va)//<=va and >va
	{
		if(!p)return make_pair(0,0);
		if(w[p]<=va)
		{
			pair<int,int>s=split_by_value(ch[p][1],va);
			ch[p][1]=s.first;pushup(p);
			return make_pair(p,s.second);
		}
		else
		{
			pair<int,int>s=split_by_value(ch[p][0],va);
			ch[p][0]=s.second;pushup(p);
			return make_pair(s.first,p);
		}
	}
	void insert(int &p,int va)
	{
		++tot;w[tot]=va;siz[tot]=1;
		pair<int,int>s=split_by_value(p,va);
		p=merge(merge(s.first,tot),s.second);
	}
	void erase(int &p,int va)
	{
		pair<int,int>s=split_by_value(p,va);
		p=merge(split_by_value(s.first,va-1).first,s.second);
	}
	int qrank(int &p,int va)
	{
		pair<int,int>s=split_by_value(p,va);
		int res=siz[s.first];
		p=merge(s.first,s.second);
		return res;
	}
}
int n,q,p[200020],w[200020],tot,ch[400040][2],rt[400040],pos[200020],f[400040];
long long sum[400040],ans[400040];
vector<int>s[400040];
void build(int &k,int l,int r)
{
	k=++tot;
	if(l==r){s[k].emplace_back(p[l]);pos[l]=k;treap::build(rt[k],0,0,s[k]);return;}
	int mid=l;
	for(int i=l+1;i<r;++i)if(w[i]<w[mid])mid=i;
	build(ch[k][0],l,mid);f[ch[k][0]]=k;
	build(ch[k][1],mid+1,r);f[ch[k][1]]=k;
	int t0=0,t1=0,l0=s[ch[k][0]].size(),l1=s[ch[k][1]].size(),t=0;
	s[k].resize(r-l+1);
	while(t0<l0&&t1<l1)
	{
		if(s[ch[k][0]][t0]<s[ch[k][1]][t1])s[k][t++]=s[ch[k][0]][t0++],sum[k]+=t1;
		else s[k][t++]=s[ch[k][1]][t1++];
	}
	while(t0<l0)s[k][t++]=s[ch[k][0]][t0++],sum[k]+=t1;
	while(t1<l1)s[k][t++]=s[ch[k][1]][t1++];
	ans[k]=ans[ch[k][0]]+ans[ch[k][1]]+min(sum[k],1ll*l0*l1-sum[k]);
	if(k>1)treap::build(rt[k],0,r-l,s[k]);
}
void erase(int x)
{
	// printf("erase:%d %d\n",x,p[x]);
	for(int k=pos[x],w=p[x];k>1;k=f[k])
	{
		treap::erase(rt[k],w);
		int &rt0=rt[ch[f[k]][0]],&rt1=rt[ch[f[k]][1]];
		if(k==ch[f[k]][0])sum[f[k]]-=treap::qrank(rt1,w);
		else sum[f[k]]-=treap::siz[rt0]-treap::qrank(rt0,w);
		ans[f[k]]=ans[ch[f[k]][0]]+ans[ch[f[k]][1]]+min(sum[f[k]],1ll*treap::siz[rt0]*treap::siz[rt1]-sum[f[k]]);
	}
	// for(int i=1;i<=tot;++i)printf("%d %d %lld %lld\n",ch[i][0],ch[i][1],sum[i],ans[i]);
	// for(int i=1;i<=tot;++i)treap::print(rt[i]),printf("\n");	
}
void insert(int x)
{
	// printf("insert:%d %d\n",x,p[x]);
	for(int k=pos[x],w=p[x];k>1;k=f[k])
	{
		treap::insert(rt[k],w);
		int &rt0=rt[ch[f[k]][0]],&rt1=rt[ch[f[k]][1]];
		if(k==ch[f[k]][0])sum[f[k]]+=treap::qrank(rt1,w);
		else sum[f[k]]+=treap::siz[rt0]-treap::qrank(rt0,w);
		ans[f[k]]=ans[ch[f[k]][0]]+ans[ch[f[k]][1]]+min(sum[f[k]],1ll*treap::siz[rt0]*treap::siz[rt1]-sum[f[k]]);
	}
	// for(int i=1;i<=tot;++i)printf("%d %d %lld %lld\n",ch[i][0],ch[i][1],sum[i],ans[i]);
	// for(int i=1;i<=tot;++i)treap::print(rt[i]),printf("\n");
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)p[i]=read();
	for(int i=1;i<n;++i)w[i]=read();
	build(ch[0][0],1,n);
	// for(int i=1;i<=tot;++i)printf("%d %d %lld %lld\n",ch[i][0],ch[i][1],sum[i],ans[i]);
	// for(int i=1;i<=tot;++i)treap::print(rt[i]),printf("\n");
	q=read();
	while(q--)
	{
		static int x,y;
		x=read(),y=read();
		if(x!=y)
		{
			erase(x),erase(y);
			swap(p[x],p[y]);
			insert(x),insert(y);			
		}
		print(ans[1]);putc('\n');
	}
	flush();
	return 0;
}