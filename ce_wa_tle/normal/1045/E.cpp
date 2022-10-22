#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1e5+9,e7=1e7+7,inf=1e17;typedef ll aN[N];
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{ll x,y,c;void read(){x=readll(),y=readll(),c=readll();}}p_[N];const pt*p=p_;aN a,b,q,bdry;
ll operator*(const pt&a,const pt&b){return a.x*b.y-a.y*b.x;}
int operator<(const pt&a,const pt&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
pt operator-(const pt&a,const pt&b){return(pt){a.x-b.x,a.y-b.y,0};}
ll cnt=0;aN fr,to;void add(ll u,ll v){fr[++cnt]=u,to[cnt]=v;}
#define add(a,b) p[a].c==p[b].c||(exit(__LINE__),0),add(a,b)
ll calc(const pt&a,const pt&b,const pt&c){return(b-a)*(c-a);}
ll calc(ll a,ll b,ll c){return calc(p[a],p[b],p[c]);}int cmp1(ll a,ll b){return p[a]<p[b];}
ll getc(ll l,ll r,ll c){static aN s;ll t=0;rep(i,l,r)if(p[a[i]].c==c)s[++t]=i;return t?s[rand()%t+1]:0;}
struct cmp{const pt set,jz;cmp(ll h,ll d):set(p[h]),jz(p[d]-p[h]){}int operator()(ll sa,ll sb)
{const pt&a=p[sa]-set,&b=p[sb]-set;const ll ma=jz*a>=0,mb=jz*b>=0;return ma!=mb?ma>mb:a*b>0;}};
void solve(ll u,ll v,ll w,ll l,ll r){//printf("s=%lld %lld %lld\n",u,v,w);rep(i,l,r)printf("%lld ",a[i]);puts("");
    ll x=getc(l,r,p[u].c);if(!x){rep(i,l,r)add(v,a[i]);return;}std::swap(a[x],a[l++]),x=a[l-1];//,printf("x=%lld\n",x);
    ll nl=l-1,nr=r+1,nk=l-1;add(u,x);//memset(b,0,sizeof(b));
    rep(i,l,r)(calc(v,x,a[i])>=0&&calc(x,u,a[i])>=0?b[++nl]:calc(w,x,a[i])>=0?a[++nk]:b[--nr])=a[i];
    memcpy(b+nl+1,a+l,sizeof(ll)*(nk-l+1)),memcpy(a+l,b+l,sizeof(ll)*(r-l+1));
//    rep(i,l,r)printf("%lld ",a[i]);puts("");printf("[%lld,%lld][%lld,%lld][%lld,%lld]\n",l,nl,nl+1,nr-1,nr,r);
    solve(v,x,u,l,nl),solve(x,v,w,nl+1,nr-1),solve(w,u,x,nr,r);
}int main(){
    ll n=readll(),u;rep(i,1,n)p_[a[i]=i].read();std::sort(a+1,a+n+1,cmp1);ll h,t;q[2]=a[1],q[h=1]=q[t=3]=a[2];
    rep(i,3,n){u=a[i];while(h<=t-1&&calc(u,q[h],q[h+1])<=0)h++;while(h<=t-1&&calc(u,q[t],q[t-1])>=0)t--;q[--h]=q[++t]=u;}
    ll gs=0;ref(i,h,t)gs+=p[q[i]].c!=p[q[i+1]].c,bdry[q[i]]=1/*,printf("%lld ",q[i]);puts("")*/;if(gs>2)return puts("Impossible");
    if(!gs){ll x=getc(1,n,p[q[1]].c^1);if(!x)rep(i,2,n)add(1,i);else{
        std::swap(a[1],a[x]),x=a[1];std::sort(a+2,a+n+1,cmp(x,q[h]));if(q[h]!=a[2])exit(36);
//        rep(i,1,n)printf("%lld ",a[i]);puts("");
        ll lst=2;rep(i,3,n)if(bdry[a[i]])add(a[lst],a[i]),solve(x,a[lst],a[i],lst+1,i-1),lst=i;
        ll i=2;solve(x,a[lst],a[i],lst+1,n);}
    }else{
       ll cl[2]={},cf[2]={};ref(i,h,t)if(p[q[i]].c!=p[q[i+1]].c)cl[p[q[i]].c]=q[i],cf[p[q[i+1]].c]=q[i+1];
       ll lf=1,rt=n;a[1]=cl[0],a[n]=cl[1];rep(i,1,n)if(i!=cl[0]&&i!=cl[1])(calc(cl[0],cl[1],i)>=0?a[++lf]:a[--rt])=i;
       std::sort(a+1,a+lf+1,cmp(cl[1],cf[0])),std::sort(a+rt,a+n+1,cmp(cl[0],cf[1]));ll lst;
//       printf("l==%lld %lld %lld %lld\n",cl[0],cl[1],lf,a[n]);rep(i,1,n)printf("%lld ",a[i]);puts("");
       lst=1;rep(i,2,lf)if(bdry[a[i]])add(a[lst],a[i]),solve(cl[1],a[lst],a[i],lst+1,i-1),lst=i;
       lst=rt;rep(i,rt+1,n)if(bdry[a[i]])add(a[lst],a[i]),solve(cl[0],a[lst],a[i],lst+1,i-1),lst=i;
    }printf("%lld\n",cnt);rep(i,1,cnt)printf("%lld %lld\n",fr[i]-1,to[i]-1);return 0;
}//0 black 1 white
/*
7
0 0 1
7 0 1
3 1 0
1 2 1
3 2 0
4 3 1
2 6 1
*/
/*
7
0 0 1
1 0 0
0 1 0
1 1 1
3 2 0
-3 -2 0
-3 2 1

*/