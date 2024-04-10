#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;typedef long double ld;
const ll inf=0x3f3f3f3f3f3f3f3f;
using std::max;
using std::min;
inline ll readll(void){
    ll x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
    for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
    return x*w;
}
inline void writell(ll x,int c='\0'){
    static ll s[112];ll*n=s;
    while(x||n==s)*++n=x%10,x/=10;
    while(n!=s)putchar(*n--^48);
    if(c)putchar(c);
}
inline ll iabs(ll x){
    return max(x,-x);
}
inline int readchar(void){
    int ch=getchar();
    for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
    return ch;
}
bool p1;
struct line{ll k,b;ll operator()(ll x)const{return k*x+b;}}li[514514];ll id[514514<<2],lson[514514<<2],rson[514514<<2];
struct que{ll x,y,id;void read(ll i){x=readll(),y=readll(),id=i;}operator ll()const{return y;}}q[514514];
struct oper{ll x,y;}st[9145141];
ll cnt=0,top=0;
void add(ll&u,ll l,ll r,ll x){
	ll mid=(l+r)>>1;if(!u)u=++cnt;
    if(li[id[u]](mid)>li[x](mid))st[++top]=(oper){u,id[u]},std::swap(x,id[u]);
	if(li[id[u]](l)<=li[x](l)&&li[id[u]](r)<=li[x](r))return;
	add(lson[u],l,mid,x),add(rson[u],mid+1,r,x);
}
ll query(ll u,ll l,ll r,ll x){
//    printf("q=%lld %lld %lld %lld\n",u,l,r,x);
    if(!u)return inf;ll mid=(l+r)>>1;return std::min(x>=l&&x<=r?/*printf("%lld\n",li[id[u]](x)),*/li[id[u]](x):inf,x<=mid?query(lson[u],l,mid,x):query(rson[u],mid+1,r,x));
}
ll a[514514],ans[514514],lst[814514],sta[814514];
bool p2;
int main(void){
   // IO(function);
//    dprintf("%.2lfMiB",(&p2-&p1)/1048576.0);
    ll n=readll();
    rep(i,1,n)a[i]=readll();
    ll t=readll();
    rep(i,1,t)q[i].read(i);
    std::sort(q+1,q+t+1);
    ll now=0,x=1,y=0,root=0;li[0]=(line){0,inf};
//	dprintf("%ld\n",clock());
    ll s=0,c=0;
    rep(i,1,t){
    	while(now<q[i].y){
    	    ++now;while(s&&a[now]<=a[sta[s]])s--;
//    	    printf("t=%lld %lld\n",top,lst[sta[s]]);
            while(top&&top>lst[sta[s]])id[st[top].x]=st[top].y,top--;
//    	    printf("t=%lld %lld\n",top,lst[sta[s]]);
    		x--,y-=a[now],li[now]=(line){a[now],y-x*a[now]};
//    		if(++c%1000==0)dprintf("%lld\n",top);
			lst[sta[++s]=now]=top;//printf("nt=%lld\n",top);
            add(root,-n,1e9,now);lst[sta[++s]=now]=top;//printf("nt=%lld\n",top);
//    	    rep(j,1,s)printf("%lld ",a[sta[j]]);puts("");
//            printf("y=%lldx+%lld(x in[%lld,1e9])\n",li[now].k,li[now].b,x);
		}
		ans[q[i].id]=query(root,-n,1e9,q[i].x+x)-y;
//		printf("y(%lld)=%lld\n",q[i].x+x,ans[q[i].id]+y);
	}
//	dprintf("%ld\n",clock());
	rep(i,1,t)writell(ans[i],'\n');
//	dprintf("%ld\n",clock());
    return 0;
}