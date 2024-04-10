/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
#define int long long
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1; y=0;
        return a;
    }
    int xx,yy;
    int ret=exgcd(b,a%b,xx,yy);
    y=xx-(a/b)*yy; x=yy;
    return ret;
}

int n,m,x,y,vx,vy,mm,nn;
signed main()
{
    n=read(); m=read(); x=read(); y=read(); vx=read(); vy=read();
    mm=m; nn=n;
    if(!vx){
        if(x!=0&&x!=n){
            puts("-1");
            return 0;
        }
        else{
            if(vy==-1){
                printf("%lld 0\n",x);
            }
            else printf("%lld %lld\n",x,m);
        }
        return 0;
    }
    if(!vy){
        if(y!=0&&y!=m){
            puts("-1");
            return 0;
        }
        else{
            if(vx==-1) printf("0 %lld\n",y);
            else printf("%lld %lld\n",y,n);
        }
        return 0;
    }
    int a,b;
    if(vx*vy>0){//a*n-b*m=x-y
        int del=x-y;
        int g=exgcd(n,m,a,b);
        if(del%g!=0){puts("-1"); return 0;}
        a*=(del/g); b*=(del/g);
        b=-b; m/=g; n/=g;
        b-=(a-(a%m))/m*n; a%=m;
        a-=(b-(b%n))/n*m; b%=n;
        if(x==y) a=m,b=n;
        if(vx==-1&&a>0){
            int d=(a+m-1)/m;
            a-=m*d; b-=n*d;
        }
        if(vy==-1&&b>0){
            int d=(b+n-1)/n;
            b-=d*n; a-=d*m;
        }
        if(vx==1&&a<0){
            int d=(_abs(a)+m-1)/m;
            a+=m*d; b+=n*d;
        }
        if(vy==1&&b<0){
            int d=(_abs(b)+n-1)/n;
            b+=d*n; a+=d*m;
        }
    }
    else{//a*n+b*m=x+y
        int del=x+y;
        int g=exgcd(n,m,a,b);
        if(del%g!=0){puts("-1"); return 0;}
        a*=(del/g); b*=(del/g);
        m/=g; n/=g;
        b+=(a-(a%m))/m*n; a%=m;
        a+=(b-(b%n))/n*m; b%=n;
        if(vx==-1&&a>0){
            int d=(a+m-1)/m;
            a-=m*d; b+=n*d;
        }
        if(vx==1&&a<0){
            int d=(_abs(a)+m-1)/m;
            a+=m*d; b-=n*d;
        }
        if(vy==-1&&b>0){
            int d=(b+n-1)/n;
            b-=d*n; a+=d*m;
        }
        if(vy==1&&b<0){
            int d=(_abs(b)+n-1)/n;
            b+=d*n; a-=d*m;
        }
    }
    m=mm; n=nn;
    if(a%2==0){
        if(b%2==0) printf("0 0");
        else printf("0 %lld\n",m);
    }
    else{
        if(b%2==0) printf("%lld 0\n",n);
        else printf("%lld %lld\n",n,m);
    }
    return 0;
}