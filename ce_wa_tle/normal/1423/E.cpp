#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e6+7,Q=1e6+7,V=42;const ld eps=1e-7;
ld sqr(ld x){return x*x;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}ld readld(){
	ll x=0,w=1;ld s=0,d=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());
    if(c=='.')for(c=getchar();c>='0'&&c<='9';s+=(d*=0.1)*(c^48),c=getchar());return(x+s)*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct pt{
    ld x,y;ld dis2()const{return x*x+y*y;}
    void read(){x=readld(),y=readld();}
    pt rt()const{return(pt){-y,x};}
};
pt operator-(const pt&a,const pt&b){return(pt){a.x-b.x,a.y-b.y};}
pt operator+(const pt&a,const pt&b){return(pt){a.x+b.x,a.y+b.y};}
ld operator*(const pt&a,const pt&b){return a.x*b.y-a.y*b.x;}
pt operator*(const pt&a,ld b){return(pt){a.x*b,a.y*b};}
bool p1;pt p[N],*now=p;
struct dbx{
    pt*p;ll k;ld area;
    void read(){p=now;now+=k=readll();ref(i,0,k)p[i].read();ref(i,0,k)area+=p[i]*p[(i+1)%k]/2;}
    int check(const pt&o,ld r)const{
        ll c=0;//puts("");
        ref(i,0,k){
            pt a=p[i]-o,b=p[(i+1)%k]-o;if(a.dis2()<=r*r+eps)return 1;
            ((a.x>eps)^(b.x>eps))&&((a.x>eps)^(a*b>eps))&&++c;
            #define print(xx,c) printf("%.6lf,%.6lf%c",(double)(xx).x,(double)(xx).y,c)
            pt c=b-a,m=c.rt()*(b*a/c.dis2());/*
            print(a+o,' '),print(b+o,' '),print(c,' '),print(m,'\n');*/if(m.dis2()<=r*r&&m*a>eps&&m*b<-eps)return 1;
        }return c&1;
    }
}s[N];ll v[N];
bool p2;
int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0);
    ll n=(readld(),readld(),readld());rep(i,1,n)s[i].read();ll q=readll();
    rep(i,1,q){
        pt o;o.read();ld r=readld(),ans=0;ll c=0;
        rep(j,1,n)if((v[j]=s[j].check(o,r)))ans+=s[j].area,c++;
//        if(n==20)printf("%.6lf,%.6lf %.6lf\n",(double)o.x,(double)o.y,(double)r);
        printf("%.6lf %lld ",(double)ans,c);rep(i,1,n)if(v[i])printf("%lld ",i-1);puts("");
    }return 0;
}
/*
0 0 1
4 1 1 100 1 100 100 1 100
1
0 0 0
1
0 0 1
4 97.5013 61.2682 114.602 61.2682 114.602 72.0541 97.5013 72.0541
1
120.003000,74.000300 6.000600
*/