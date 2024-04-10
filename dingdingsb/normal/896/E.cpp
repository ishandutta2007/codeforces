#include<bits/stdc++.h>
using namespace std;
namespace in{
	char buf[1<<21],*p1=buf,*p2=buf;
	inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
	template <typename T>inline void read(T& t){
		t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
	    while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
	}
	template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
	char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
	inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
	inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
	template <typename T>void write(T x) {
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
const int N=1e5+600,block=320;
int fa[N],val[N];
struct DSU{
	int sz[N],id[N];
	inline int getfa(int x){
		return x==fa[x]?x:fa[x]=getfa(fa[x]);
	}
	inline void merge(int p,int x,int y){
		if(id[y])fa[id[x]+(p-1)*block]=id[y]+(p-1)*block;
		else{
			id[y]=id[x];
			val[id[y]+(p-1)*block]=y;
		}
		sz[y]+=sz[x];
		id[x]=sz[x]=0;
	}
}D[block+5];
int n,m;
int a[N];
#define pos(x) ((x)-1)/block+1
int Max[N];
int tag[N];
inline void Break(int p){
	for(int i=(p-1)*block+1;i<=min(n,p*block);i++)
		a[i]=val[D[p].getfa(i)],
		D[p].sz[a[i]]=D[p].id[a[i]]=0,
		a[i]-=tag[p];
	for(int i=(p-1)*block+1;i<=min(n,p*block);i++)fa[i]=0;
	tag[p]=0;
}
inline void Build(int p){
	Max[p]=0;
	for(int i=(p-1)*block+1;i<=p*block;i++){
		Max[p]=max(Max[p],a[i]);
		if(D[p].id[a[i]]==0)
			fa[i]=i,
			D[p].id[a[i]]=i-(p-1)*block,
			val[i]=a[i];
		else
			fa[i]=D[p].id[a[i]]+(p-1)*block;
		D[p].sz[a[i]]++;
	}
}
inline void update(int p,int l,int r,int x){
	Break(p);
	for(int i=l;i<=r;i++)if(a[i]>x)a[i]-=x;
	Build(p);
}
inline void UPDATE(int p,int x){
	if(Max[p]-tag[p]>=x*2){
		for(int i=tag[p]+1;i<=tag[p]+x;i++)
			if(D[p].id[i])
				D[p].merge(p,i,i+x);
		tag[p]+=x;
	}else{
		for(int i=Max[p];i>tag[p]+x;i--)
			if(D[p].id[i])
				D[p].merge(p,i,i-x);
		Max[p]=min(tag[p]+x,Max[p]);
	}
}
inline int query(int p,int l,int r,int x){
	int ans=0;
	for(int i=l;i<=r;i++)
		if(val[D[p].getfa(i)]-tag[p]==x)
			ans++;
	return ans;
}
inline int QUERY(int p,int x){
	if(x+tag[p]>1e5+1)return 0;
	return D[p].sz[x+tag[p]];
}
signed main(){
	in::read(n,m);
    for(int i=1;i<=n;i++)in::read(a[i]);
	for(int i=1;i<=pos(n);i++)Build(i);
	while(m--){
		int op,l,r,x;
		in::read(op,l,r,x);
		if(op==1){
			int pl=pos(l),pr=pos(r);
			if(pl==pr)update(pl,l,r,x);
			else{
				update(pl,l,pl*block,x);
				update(pr,(pr-1)*block+1,r,x);
				for(int i=pl+1;i<=pr-1;i++)UPDATE(i,x);
			}
		}else{
			int pl=pos(l),pr=pos(r);
			if(pl==pr)printf("%d\n",query(pl,l,r,x));
			else{
				int ans=0;
				ans+=query(pl,l,pl*block,x);
				ans+=query(pr,(pr-1)*block+1,r,x);
				for(int i=pl+1;i<=pr-1;i++)ans+=QUERY(i,x);
				printf("%d\n",ans);
			}
		}
	}
    return 0;
}