#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=3e5+9,e7=1e7+7,inf=1e17;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y,c;void read(){x=readll(),y=readll(),c=0;}}p[N];ll q_[2*N],*q=q_+N;
ll operator*(const pt&a,const pt&b){return a.x*b.y-a.y*b.x;}
int operator<(const pt&a,const pt&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
pt operator-(const pt&a,const pt&b){return(pt){a.x-b.x,a.y-b.y,0};}
ll calc(const pt&a,const pt&b,const pt&c,ll w){
    ll res=(b-a)*(c-a);return res*w>0?1:res==0?(a-b).x*(c-b).x<=0&&(a-b).y*(c-b).y<=0:0;
}
#define check(s)\
    do{q[2]=0,q[h=1]=q[t=3]=1;rep(i,2,n)if(p[i].c!=s){while(h<=t-1&&calc(p[i],p[q[h]],p[q[h+1]],1))h++;\
    while(h<=t-1&&calc(p[i],p[q[t]],p[q[t-1]],-1))t--;q[--h]=q[++t]=i;/*rep(i,h,t)printf("(%lld,%lld)",p[q[i]].x,p[q[i]].y);puts("");*/}\
    ref(i,h,t)if((p[q[i]].x|p[q[i]].y)&1)return puts("Ani"),0;/*puts("");*/}while(0)
int main(){
    ll n=readll();rep(i,1,n)p[i].read();std::sort(p+1,p+n+1);ll h,t;check(1);rep(i,h,t)if(q[i])p[q[i]].c|=1<<(i&1);
//    rep(i,0,n)printf("%lld\n",p[i].c);
    check(1);check(2);check(3);puts("Borna");return 0;
}//printf("%lld\n",calc((pt){2,0,0},(pt){1,1,0},(pt){0,2,0},-1));