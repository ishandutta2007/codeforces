#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=4e5+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
struct four_stone{
    ll val[4],nx[1111],ny[1111],top,t,g,s;four_stone():top(0),t(0),g(0),s(0){}void sort(){std::sort(val,val+4);}
    void read(){
        ref(i,0,4)val[i]=readll();sort();ref(i,0,4)g=gcd(g,val[i]-val[0]);
        t=g?val[0]%g:val[0];ref(i,0,4)s+=1&(val[i]=g?(val[i]-t)/g:0);
    }void move(ll x,ll y){if(!(0<=x&&0<=y&&x<=3&&y<=3))exit(7);if(val[x]!=val[y])nx[++top]=val[x],ny[top]=val[y],val[x]=2*val[y]-val[x];}
    void to1(){
        while(val[3]>val[0]+1){
            ll d_4=(val[3]-val[0]+3)/4,d1=std::min(val[3]-val[1],val[1]-val[0]),d2=std::min(val[3]-val[2],val[2]-val[0]);
            /*ref(i,0,4)printf("%lld ",val[i]);puts("");*/while(d1<d_4&&d2<d_4){
                ll x=2-(d1<d2),y=val[x^3]-val[0]<=val[3]-val[x^3];move(x,(1^y)<<1|(x-1)),move(x,(2-x)<<1|(y^1));
    			sort(),d1=std::min(val[3]-val[1],val[1]-val[0]),d2=std::min(val[3]-val[2],val[2]-val[0]);//printf("2=");ref(i,0,4)printf("%lld ",val[i]);puts("");
            }ll x=2-(d1>=d_4),y=(x==1)^(val[3]-val[x]>=val[x]-val[0]);
            move((y+1)^x,x);if(y)move(3^x,x);sort();
        }if(val[0]&1)ref(i,0,3)if(val[i]&1)move(i,3);sort();
    }void moveto(ll to){
        ll dis=(to-val[0])/2;while(val[3]<val[0]+dis)move(2,0),move(1,3),sort();while(dis){
        while(dis>=val[3]-val[0]){dis-=val[3]-val[0];ref(i,0,4)move(i,3);ref(i,0,4)move(i,0);sort();}
        move(0,1),move(3,2),sort();}while(val[3]>val[0]+1||val[0]&1)move(0,1),move(3,2),sort();
    }void print(ll rev=0)const{
        if(rev)per(i,top,1)printf("%lld %lld\n",(2*ny[i]-nx[i])*g+t,ny[i]*g+t);
        else rep(i,1,top)printf("%lld %lld\n",nx[i]*g+t,ny[i]*g+t);
    }
}a,b;
int main(){
    a.read(),b.read();if(a.t!=b.t||a.g!=b.g||a.s!=b.s)return puts("-1"),0;a.to1(),b.to1();
    a.val[0]<b.val[0]?a.moveto(b.val[0]):b.moveto(a.val[0]);//ref(i,0,4)printf("%lld %lld\n",a.val[i],b.val[i]);
    printf("%lld\n",a.top+b.top),a.print(),b.print(1);return 0;
}
//a<b a+2b=a' b+2b>a' b>a'/3
//0 1 2 5 12 29 
//x kx (2k+1)x
//(2k+1)/k=k
//k^2-2k-1=0
//(k-1)^2-2=0
//k=1+s2
//if(y)if(x==1)move(1,0),move(1,2)else move(2,1),move(2,0)
//else if(x==1)move(1,2),move(1,3)else move(2,3),move(2,1)
//if(x==1)if(y) move(3,1),move(2,1);else move(0,1);
//   else if(y) move(0,2),move(1,2);else move(3,2);