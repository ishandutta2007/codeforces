/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9+10;
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
const int N=100005;
ll sqr(int x){return 1ll*x*x;}
int na,nb,nc,a[N],b[N],c[N];
ll f(int x,int y,int z){
    if(x<0||y<0||z<0) return INF;
    if(x>=inf||y>=inf||z>=inf) return INF;
    return sqr(x-y)+sqr(y-z)+sqr(x-z);
}
ll calcc(int x,int y){
    if(x>y) swap(x,y);
    int l=lower_bound(c,c+nc+1,x)-c;
    int r=upper_bound(c,c+nc+1,y)-c-1;
    if(l>r) return min(f(c[l],x,y),f(c[r],x,y));
    ll best=INF; int mid1,mid2;
    while(l+5<=r){
        mid1=(l+l+r)/3,mid2=(l+r+r)/3;
        ll val1=f(c[mid1],x,y),val2=f(c[mid2],x,y);
        if(val1<=val2) best=val1,r=mid2;
        else best=val2,l=mid1;
    }
    for(int i=l;i<=r;i++) checkmin(best,f(c[i],x,y));
    return best;
}
ll calca(int x,int y){
    if(x>y) swap(x,y);
    int l=lower_bound(a,a+na+1,x)-a;
    int r=upper_bound(a,a+na+1,y)-a-1;
    if(l>r) return min(f(a[l],x,y),f(a[r],x,y));
    ll best=INF; int mid1,mid2;
    while(l+5<=r){
        mid1=(l+l+r)/3,mid2=(l+r+r)/3;
        ll val1=f(a[mid1],x,y),val2=f(a[mid2],x,y);
        if(val1<=val2) best=val1,r=mid2;
        else best=val2,l=mid1;
    }
    for(int i=l;i<=r;i++) checkmin(best,f(a[i],x,y));
    return best;
}
ll calcb(int x,int y){
    if(x>y) swap(x,y);
    int l=lower_bound(b,b+nb+1,x)-b;
    int r=upper_bound(b,b+nb+1,y)-b-1;
    if(l>r) return min(f(b[l],x,y),f(b[r],x,y));
    ll best=INF; int mid1,mid2;
    while(l+5<=r){
        mid1=(l+l+r)/3,mid2=(l+r+r)/3;
        ll val1=f(b[mid1],x,y),val2=f(b[mid2],x,y);
        if(val1<=val2) best=val1,r=mid2;
        else best=val2,l=mid1;
    }
    for(int i=l;i<=r;i++) checkmin(best,f(b[i],x,y));
    return best;
}

int main()
{
    int T=read();
    while(T--){
        ll ans=INF;
        na=read(),nb=read(),nc=read();
        for(int i=1;i<=na;i++) a[i]=read();
        for(int i=1;i<=nb;i++) b[i]=read();
        for(int i=1;i<=nc;i++) c[i]=read();
        sort(a+1,a+na+1); sort(b+1,b+nb+1); sort(c+1,c+nc+1);
        a[0]=-inf; a[++na]=inf+inf;
        b[0]=-inf; b[++nb]=inf+inf; 
        c[0]=-inf; c[++nc]=inf+inf;
        for(int i=1;i<na;i++){
            int pos=lower_bound(b,b+nb+1,a[i])-b;
            checkmin(ans,calcc(a[i],b[pos]));
            pos--; checkmin(ans,calcc(a[i],b[pos]));
            pos=lower_bound(c,c+nc+1,a[i])-c;
            checkmin(ans,calcb(a[i],c[pos]));
            pos--; checkmin(ans,calcb(a[i],c[pos]));
        } 
        for(int i=1;i<nb;i++){
            int pos=lower_bound(a,a+na+1,b[i])-a;
            checkmin(ans,calcc(b[i],a[pos]));
            pos--; checkmin(ans,calcc(b[i],a[pos]));
            pos=lower_bound(c,c+nc+1,b[i])-c;
            checkmin(ans,calca(b[i],c[pos]));
            pos--; checkmin(ans,calca(b[i],c[pos]));
        }
        for(int i=1;i<nc;i++){
            int pos=lower_bound(a,a+na+1,c[i])-a;
            checkmin(ans,calcb(c[i],a[pos]));
            pos--; checkmin(ans,calcb(c[i],a[pos]));
            pos=lower_bound(b,b+nb+1,c[i])-b;
            checkmin(ans,calca(c[i],b[pos]));
            pos--; checkmin(ans,calca(c[i],b[pos]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}