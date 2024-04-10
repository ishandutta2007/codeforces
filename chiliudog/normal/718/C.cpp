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
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
const int maxn=100005;
const int mod=1e9+7;
struct mat{
    int n,m,a[3][3];
    inline mat(){}
    inline mat(int _n,int _m){n=_n;m=_m;clr(a);}
};
mat res;
inline mat operator * (const mat &a,const mat &b){
//    assert(a.m==b.n);
    res=mat(a.n,b.m);
    rep(i,1,res.n)rep(j,1,res.m)rep(k,1,a.m)
        res.a[i][j]=(res.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%mod;
    return res;
}
inline mat operator + (const mat &a,const mat &b){
//    assert(a.n==b.n);assert(a.m==b.m);
    res=mat(a.n,b.m);
    rep(i,1,res.n)rep(j,1,res.m)res.a[i][j]=(a.a[i][j]+b.a[i][j])%mod;
    return res;
}
int l[maxn<<2],r[maxn<<2];
mat tag[maxn<<2],sum[maxn<<2];
mat one,addd,op;
inline void update(int x){
    sum[x]=sum[ls(x)]+sum[rs(x)];
}
inline void build(int x,int lq,int rq){
    l[x]=lq;r[x]=rq;tag[x]=one;sum[x]=mat(2,1);if(lq==rq){sum[x].a[1][1]=1;return;}
    int md=(lq+rq)>>1;build(ls(x),lq,md);build(rs(x),md+1,rq);update(x);
}
inline void pushdown(int x){
    if(l[x]==r[x])return;
    if(tag[x].a[2][2]||tag[x].a[1][1]||tag[x].a[1][2]||tag[x].a[2][1]){
        tag[ls(x)]=tag[ls(x)]*tag[x];
        tag[rs(x)]=tag[rs(x)]*tag[x];
        sum[ls(x)]=tag[(x)]*sum[ls(x)];
        sum[rs(x)]=tag[(x)]*sum[rs(x)];
        tag[x]=one;
    }
}
inline void add(int x,int lq,int rq){
    pushdown(x);
    if(l[x]>=lq&&r[x]<=rq){
        sum[x]=addd*sum[x];
        tag[x]=tag[x]*addd;
        return;
    }int md=(l[x]+r[x])>>1;
    if(lq<=md)add(ls(x),lq,rq);
    if(rq>md)add(rs(x),lq,rq);
    update(x);
}
inline mat query(int x,int lq,int rq){
    pushdown(x);
    if(l[x]>=lq&&r[x]<=rq){
        return sum[x];
    }
    int md=(l[x]+r[x])>>1;mat res=mat(2,1);
    if(lq<=md)res=res+query(ls(x),lq,rq);
    if(rq>md)res=res+query(rs(x),lq,rq);
    return res;
}
inline mat powmod(mat a,int b){
    mat res=mat(2,2);res.a[1][1]=res.a[2][2]=1;
    for(;b;b>>=1){
        if(b&1)res=res*a;a=a*a;
    }return res;
}int n,m;
int main(){
    read(n);read(m);one=mat(2,2);one.a[1][1]=one.a[2][2]=1;
    build(1,1,n);
    op=mat(2,2);op.a[1][2]=op.a[1][1]=op.a[2][1]=1;
    rep(i,1,n){
        int x;read(x);addd=powmod(op,x-1);
        add(1,i,i);
    }
    rep(i,1,m){
        int t;read(t);
        if(t==1){
            int l,r,x;read(l);read(r);read(x);
            addd=powmod(op,x);
            add(1,l,r);
        }else{
            int l,r;read(l);read(r);mat ans=query(1,l,r);
            printf("%d\n",ans.a[1][1]);
        }
    }
	return 0;
}