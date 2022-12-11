#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int siz=400;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	inline int read()
	{
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
	char buff[N],*T=buff;
	inline void flush(){fwrite(buff,1,T-buff,stdout),T=buff;}
	inline void putc(char ch){T==buff+N?flush(),0:0,*T++=ch;}
	inline void print(int x)
	{
		if(!x){putc('0');return;}
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp--]^48);
	}
}
using io::read;
using io::putc;
using io::print;
using io::flush;
int n,q,p,bl[150050],bnum,len[410],st[410],ed[410],a[150050],cnt[410][150050],hv[410][6],in[410][410],tag[410],ans[6];
struct data
{
	int l,r,id;
	friend bool operator < (data a,data b){return a.l<b.l;}
};
set<data>s;
bool vis[150050];
int ncnt[150050],stk[150050];
void rebuild(int b,int l,int r,int w)
{
	if(tag[b])for(int i=st[b];i<=ed[b];++i)a[i]=tag[b];
	tag[b]=0;
	for(int i=l;i<=r;++i)a[i]=w;
	*in[b]=*hv[b]=0;
	for(int j=st[b];j<=ed[b];++j)
	{
		if(!ncnt[a[j]])in[b][++*in[b]]=a[j];
		++ncnt[a[j]];
	}
	int lim=(len[b]*p+99)/100;
	for(int j=1;j<=*in[b];ncnt[in[b][j]]=0,++j)if(ncnt[in[b][j]]>=lim)hv[b][++*hv[b]]=in[b][j];
}
inline void ins(int l,int r,int w)
{
	for(int i=bl[l];i<=bnum;++i)cnt[i][w]+=min(ed[i],r)-l+1;
}
inline void era(int l,int r,int w)
{
	for(int i=bl[l];i<=bnum;++i)cnt[i][w]-=min(ed[i],r)-l+1;
}
int main()
{
	n=read(),q=read(),p=read();
	for(int i=1;i<=n;++i)bl[i]=(i-1)/siz+1;
	bnum=bl[n];
	for(int i=1;i<bnum;++i)len[i]=siz,st[i]=(i-1)*siz+1,ed[i]=i*siz;
	len[bnum]=n-(bnum-1)*siz,st[bnum]=(bnum-1)*siz+1,ed[bnum]=n;
	for(int i=1;i<=n;++i)a[i]=read(),s.insert(data{i,i,a[i]});
	for(int i=1;i<=bnum;++i)
	{
		for(int j=st[i];j<=ed[i];++j)
		{
			if(!cnt[i][a[j]])in[i][++*in[i]]=a[j];
			++cnt[i][a[j]];
		}
		int lim=(len[i]*p+99)/100;
		for(int j=1;j<=*in[i];++j)if(cnt[i][in[i][j]]>=lim)hv[i][++*hv[i]]=in[i][j];
		for(int j=1;j<=150000;++j)cnt[i][j]+=cnt[i-1][j];
	}
	int c,x,y,id;
	while(q--)
	{
		c=read(),x=read(),y=read();
		if(c==1)
		{
			id=read();
			if(bl[x]==bl[y])rebuild(bl[x],x,y,id);
			else
			{
				rebuild(bl[x],x,ed[bl[x]],id),rebuild(bl[y],st[bl[y]],y,id);
				for(int i=bl[x]+1;i<bl[y];++i)tag[i]=hv[i][*hv[i]=1]=in[i][*in[i]=1]=id;
			}
			auto l=prev(s.upper_bound(data{x,0,0}));
			auto r=s.upper_bound(data{y,0,0});
			data left=*l,right=*prev(r);
			auto it=l;
			while(it!=r)era(max(it->l,x),min(it->r,y),it->id),it=next(it),s.erase(prev(it));
			if(left.l!=x)s.insert(data{left.l,x-1,left.id});
			if(right.r!=y)s.insert(data{y+1,right.r,right.id});
			s.insert(data{x,y,id});ins(x,y,id);
		}
		else
		{
			if(bl[x]==bl[y])
			{
				if(tag[bl[x]])
				{
					stk[++*stk]=tag[bl[x]],vis[tag[bl[x]]]=1;
					ncnt[tag[bl[x]]]+=y-x+1;
				}
				else for(int i=x;i<=y;++i)
				{
					if(!vis[a[i]])stk[++*stk]=a[i],vis[a[i]]=1;
					++ncnt[a[i]];
				}
			}
			else
			{
				if(tag[bl[x]])
				{
					stk[++*stk]=tag[bl[x]],vis[tag[bl[x]]]=1;
					ncnt[tag[bl[x]]]+=ed[bl[x]]-x+1;
				}
				else for(int i=x;i<=ed[bl[x]];++i)
				{
					if(!vis[a[i]])stk[++*stk]=a[i],vis[a[i]]=1;
					++ncnt[a[i]];
				}
				if(tag[bl[y]])
				{
					if(!vis[tag[bl[y]]])stk[++*stk]=tag[bl[y]],vis[tag[bl[y]]]=1;
					ncnt[tag[bl[y]]]+=y-st[bl[y]]+1;
				}
				else for(int i=st[bl[y]];i<=y;++i)
				{
					if(!vis[a[i]])stk[++*stk]=a[i],vis[a[i]]=1;
					++ncnt[a[i]];
				}
				for(int i=bl[x]+1;i<bl[y];++i)
					for(int j=1;j<=*hv[i];++j)if(!vis[hv[i][j]])stk[++*stk]=hv[i][j],vis[hv[i][j]]=1;
			}
		//	for(int i=1;i<=*stk;++i)printf("%d %d    ",stk[i],(bl[x]!=bl[y]?cnt[bl[y]-1][stk[i]]-cnt[bl[x]][stk[i]]:0)+ncnt[stk[i]]);printf("\n");
			int lim=((y-x+1)*p+99)/100;
			for(int i=1;i<=*stk;vis[stk[i]]=0,ncnt[stk[i]]=0,++i)
				if((bl[x]!=bl[y]?cnt[bl[y]-1][stk[i]]-cnt[bl[x]][stk[i]]:0)+ncnt[stk[i]]>=lim)ans[++*ans]=stk[i];
			print(*ans),putc(' ');
			for(int i=1;i<=*ans;++i)print(ans[i]),putc(' ');
			putc('\n');
			*ans=0,*stk=0;
		}
	}
	flush();
	return 0;
}