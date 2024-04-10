#include<bits/stdc++.h>
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
using namespace std;
const int N=5e5+10;
struct node{
    pair<long long,int>ans;
    long long tag;
    int l,r;
}T[N*8];
#define lson (x<<1)
#define rson (x<<1|1)
void pushup(int x){T[x].ans=max(T[lson].ans,T[rson].ans);}
void pushdown(int x){
    if(T[x].tag){
        T[lson].tag+=T[x].tag;T[lson].ans.first+=T[x].tag;
        T[rson].tag+=T[x].tag;T[rson].ans.first+=T[x].tag;
        T[x].tag=0;
    }
}
void build(int x,int l,int r){
    T[x].l=l,T[x].r=r;
    if(l==r){T[x].ans={0,l};return;}
    int mid=l+r>>1;
    build(lson,l,mid);build(rson,mid+1,r);
    pushup(x);
}
pair<long long,int>query(int x,int l,int r){
    if(l<=T[x].l&&T[x].r<=r)return T[x].ans;
    pushdown(x);
	int mid=T[x].l+T[x].r>>1;
    if(r<=mid)return query(lson,l,r);
    if(mid<l)return query(rson,l,r);
    return max(query(lson,l,r),query(rson,l,r));
}
void upd(int x,int l,int r,int val){
    if(l<=T[x].l&&T[x].r<=r){T[x].ans.first+=val;T[x].tag+=val;return;}
    pushdown(x);
    int mid=T[x].l+T[x].r>>1;
    if(l<=mid)upd(lson,l,r,val);
    if(mid<r)upd(rson,l,r,val);
    pushup(x);
}
int n;
struct Worker{int l,r,v;Worker(int l,int v,int r):l(l),v(v),r(r){}};
vector<Worker>a;
vector<vector<pair<pair<int,int>,int>>>opt;
#define pb push_back
signed main(){
	in::read(n);opt=vector<vector<pair<pair<int,int>,int>>>(3e5+4);
	for(int i=1,l,v,r;i<=n;i++)
		in::read(l,v,r),
		a.pb(Worker(l,v,r)),
		opt[l].pb({{v,r},1}),opt[v+1].pb({{v,r},-1});
	build(1,0,3e5);
	int ans=0,x,y;
	for(int i=0;i<=3e5+3;i++){
		for(auto OPT:opt[i])upd(1,OPT.first.first,OPT.first.second,OPT.second);
		if(T[1].ans.first>ans)
			ans=T[1].ans.first,
			x=i,y=T[1].ans.second;
	}
	printf("%d\n",ans);
	int tmp=0;
	for(auto worker:a)
		if(++tmp&&worker.l<=x&&x<=worker.v&&worker.v<=y&&y<=worker.r)
			printf("%d ",tmp);
}