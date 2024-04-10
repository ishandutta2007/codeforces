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
const int N=200005;
int n,a[N]; ll sum1[N],sum2[N],sum[N];
ll s2(int l,int r){return sum2[r]-sum2[l-1];}
ll s1(int l,int r){return sum1[r]-sum1[l-1];}
ll s(int l,int r){return sum[r]-sum[l-1];}
ll ans=0;
void find1(int x){
    int l=0,r=(n-1-x)/2,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        int pos=x+mid*2;
        ll sumc=s(1,x)+(x&1 ? s1(x+1,pos) : s2(x+1,pos));
        ll sump=s(pos+1,n)+(x&1 ? s2(x+1,pos) : s1(x+1,pos));
        if(sump>sumc) l=mid+1,best=mid;
        else r=mid-1;
    }
    ans+=best+1;
}
void find3(int x){
    int l=0,r=(n-2-x)/2,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        int pos=x+mid*2;
        ll sumc=s(1,x)+(x&1 ? s1(x+1,pos) : s2(x+1,pos))+a[n];
        ll sump=s(pos+1,n-1)+(x&1 ? s2(x+1,pos) : s1(x+1,pos));
        if(sump>sumc) l=mid+1,best=mid;
        else r=mid-1;
    }
    ans+=best+1;
}
void BC(){
    for(int i=1;i<n;i++) find1(i);//CCCPCPC..P
    for(int i=1;i<n-1;i++) find3(i);//CCCPCPC...PC
}
void find2(int x){
    int l=0,r=(n-x-1)/2,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        int pos=x+mid*2;
        ll sumc=s(2,x)+(x&1 ? s1(x+1,pos) : s2(x+1,pos));
        ll sump=s(pos+1,n)+(x&1 ? s2(x+1,pos) : s1(x+1,pos))+a[1];
        if(sump>sumc) l=mid+1,best=mid;
        else r=mid-1;
    }
    ans+=best+1;
}
void find4(int x){
    int l=0,r=(n-2-x)/2,mid,best=-1;
    while(l<=r){
        mid=(l+r)>>1;
        int pos=x+mid*2;
        ll sumc=s(2,x)+(x&1 ? s1(x+1,pos) : s2(x+1,pos))+a[n];
        ll sump=s(pos+1,n-1)+(x&1 ? s2(x+1,pos) : s1(x+1,pos))+a[1];
        //if(x==2) out(mid),out(pos),out(sumc),outln(sump);
        if(sump>sumc) l=mid+1,best=mid;
        else r=mid-1;
    }
    ans+=best+1;
}
void BP(){
    for(int i=2;i<n;i++){//PC...P
        find2(i);
    }
    for(int i=2;i<n-1;i++){//PC...PC
        find4(i);
    }
    for(int i=1;i<=n;i++){//PP
        if(s(1,i)>s(i+1,n)) ans++;
    }
}

signed main()
{
    int T=read();
    while(T--){
        n=read(); ans=0;
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        sum1[1]=a[1]; sum1[2]=a[1];
        for(int i=3;i<=n;i+=2) sum1[i]=sum1[i-2]+a[i],sum1[i+1]=sum1[i];
        for(int i=2;i<=n;i+=2) sum2[i]=sum2[i-2]+a[i],sum2[i+1]=sum2[i];       
        BC(); BP(); printf("%lld\n",ans%MOD);
    }
    return 0;
}