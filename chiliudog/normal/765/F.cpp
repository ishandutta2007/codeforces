#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=300005;
int sz;
int ne[maxn],n,m,pre[maxn];
int head;
int a[maxn];
pin b[maxn];
int bl[maxn];
struct info{
	int l,r,pre;
	inline void rd(){read(l);read(r);}
}q[maxn];
const int inf=1e9;
inline bool operator < (const info &a,const info &b){
	return bl[a.l]<bl[b.l]||(bl[a.l]==bl[b.l]&&a.r>b.r);
}
int mem[maxn],ans[maxn];
inline void del(int x){
	ne[pre[x]]=ne[x];
	pre[ne[x]]=pre[x];
}
inline int ins(int x){
	ne[x]=ne[pre[x]];
	pre[ne[pre[x]]]=x;
	ne[pre[x]]=x;
	return min(abs(a[x]-a[pre[x]]),abs(a[ne[x]]-a[x]));
}
inline void build(){
	ne[0]=n+1;pre[n+1]=n;int lst=0;
	rep(i,1,n){
		ne[lst]=b[i].w2;pre[b[i].w2]=lst;lst=b[i].w2;
	}ne[lst]=n+1;
}
int main(){
    read(n);
    a[0]=-inf;a[n+1]=-inf;
    rep(i,1,n)read(a[i]);
    rep(i,1,n)b[i]=mk(a[i],i);
    sort(b+1,b+1+n);
    read(m);sz=sqrt(n);
    rep(i,1,n)bl[i]=(i-1)/sz+1;
    rep(i,1,m)q[i].rd(),q[i].pre=i;
    sort(q+1,q+1+m);
    rep(i,1,m){
    	int j=i;
    	while(j<m&&bl[q[j+1].l]==bl[q[i].l])j++;
    	build();int l=1,r=n;
    	rep(x,1,n)mem[x]=inf;
    	int x=bl[q[i].l];
    	int p=(x-1)*sz+1,Q=min(n,x*sz);
    	while(l<Q)del(l++);
    	while(r>Q)del(r--);mem[Q]=inf;
    	while(r<n){
    		r++;
    		mem[r]=min(mem[r-1],ins(r));
    	}
    	while(l>p)ins(--l);
    	rep(k,i,j){
    		int res=mem[q[k].r];
    		while(r>q[k].r)del(r--);
    		while(l<r&&l<Q)del(l++);
    		while(l>q[k].l)res=min(res,ins(--l));
    		while(l>p)ins(--l);
    		ans[q[k].pre]=res;
    	}i=j;
    }
    rep(i,1,m)printf("%d\n",ans[i]);
    return 0;
}