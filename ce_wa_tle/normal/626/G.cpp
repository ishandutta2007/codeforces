#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=1e6+7;typedef ll aN[N];aN l,p,now;ld sum=0;ll t;//ll u;
ll readll(){
    ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll u;ld dis;operator ld()const{return fabsl(dis)<1e-9?u==0?1e-9:0:dis;}};int n_eq(ld a,ld b){return fabsl(a-b)>1e-9;}
typedef std::priority_queue<node>que;struct cpq:public que{ld ans[N];
void update(ll u,ld c){push((node){u,ans[u]=c});while(!empty()&&n_eq(top().dis,ans[top().u]))que::pop();}
void pop(){que::pop();while(!empty()&&n_eq(top().dis,ans[top().u]))que::pop();}}in,out;
ld sdel(ll u){return now[u]==l[u]?-N:now[u]<=2*l[u]?-p[u]*l[u]/((now[u]-1.0L)*now[u]):0;};
ld sadd(ll u){return now[u]<2*l[u]?p[u]*l[u]/((now[u]+1.0L)*now[u]):0;};
void cg(ll u){out.update(u,sadd(u)),in.update(u,sdel(u));}
void add(){ll u=out.top().u;sum+=out.top().dis,out.pop(),now[u]++,cg(u);}
void del(){ll u=in.top().u;sum+=in.top().dis,in.pop(),now[u]--,cg(u);}
void inc(ll u){l[u]++;if(l[u]<=now[u])sum-=p[u]*1.0L/now[u],cg(u),
t!=1&&l[u]*2==now[u]+2&&(del(),add(),0),add();else now[u]++,cg(u);}
void dec(ll u){l[u]--;if(l[u]*2>=now[u])sum+=p[u]*1.0L/now[u],cg(u),del();else 
if(now[u]==l[u]*2+1)sum+=(0.5L-l[u]*1.0L/now[u])*p[u],now[u]--,cg(u);else now[u]-=2,cg(u),add();}
int main(){
    ll n=readll(),t=::t=readll(),q=readll(),s;rep(i,1,n)p[i]=readll();rep(i,1,n)now[i]=l[i]=readll();
    rep(i,0,n)out.update(i,sadd(i)),in.update(i,-N);rep(i,1,t)add();//printf("%.8lf\n",(double)sum);
    rep(i,1,q)s=readll(),(s==1?inc:dec)(readll()),printf("%.8lf\n",(double)sum);return 0;
}