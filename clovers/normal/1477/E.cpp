/*
the vast starry sky,
bright for those who chase the light.
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
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
const int M=1000001;
struct BIT{
    ll sum[M+5]; int num[M+5];
    int lowbit(int x){return x&(-x);}
    int find(int k){
        int x=0;
        for(int i=19;i>=0;i--){
            if(x+(1<<i)>M) continue;
            if(num[x+(1<<i)]<k) k-=num[x+(1<<i)],x+=(1<<i);
        }
        return x;
    }
    void update(int x,int val){
        x++;
        for(int i=x;i<=M;i+=lowbit(i)) sum[i]+=val*(x-1),num[i]+=val;
    }
    ll query(int x){
        x++; if(x>M) x=M;
        ll ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=sum[i];
        return ret;
    }
    int Count(int x){
        x++; if(x>M) x=M;
        int ret=0;
        for(int i=x;i;i-=lowbit(i)) ret+=num[i];
        return ret;
    }
}Ta,Tb;

int n,m,q,a[N],b[N],Min=inf; ll suma=0,sumb=0;
multiset<int> sta,stb;
void init(){
    n=read(); m=read(); q=read();
    for(int i=1;i<=n;i++) a[i]=read(),suma+=a[i],checkmin(Min,a[i]),sta.insert(a[i]);
    for(int i=1;i<=m;i++) b[i]=read(),sumb+=b[i],checkmin(Min,b[i]),stb.insert(b[i]);
    for(int i=1;i<=m;i++) Tb.update(b[i],1);
    for(int i=1;i<=n;i++) Ta.update(a[i],1);
}

ll calca(int k,int c1){
    ll ret=1ll*(m-n)*c1;
    ret+=1ll*(n-1)*max(c1-k-Min,0);
    if(c1-k>0){
        int num=Tb.Count(c1-k);
        ret+=Tb.query(c1-k);
        ret-=1ll*num*(c1-k);
    }
    return ret;
}
ll calcb(int k,int c1){
    ll ret=1ll*(m-n)*c1;
    ret+=1ll*n*max(c1-k-Min,0);
    if(c1-k>0){
        int num=Tb.Count(c1-k);
        ret+=Tb.query(c1-k);
        ret-=1ll*num*(c1-k);
    }
    return ret;
}
int tot=0;
void solve(int k){
    ll ans=suma-sumb+1ll*(n-m)*k;
    ll ret=-INF;
    int l=1,r=n;
    checkmax(ret,calca(k,Ta.find(l)));
    checkmax(ret,calca(k,Ta.find(r)));
    int pos=Ta.Count(k+Min);
    for(int i=-1;i<=1;i++){
        if(pos+i>=1&&pos+i<=n) 
            checkmax(ret,calca(k,Ta.find(pos+i)));
    }
    pos=Ta.Count(*stb.rbegin()+k);
    for(int i=-1;i<=1;i++){
        if(pos+i>=1&&pos+i<=n) 
            checkmax(ret,calca(k,Ta.find(pos+i)));
    }

    l=1,r=m;
    checkmax(ret,calcb(k,Tb.find(l)));
    checkmax(ret,calcb(k,Tb.find(r)));
    pos=Tb.Count(k+Min);
    for(int i=-1;i<=1;i++){
        if(pos+i>=1&&pos+i<=m) 
            checkmax(ret,calcb(k,Tb.find(pos+i)));
    }
    pos=Tb.Count(*stb.rbegin()+k);
    for(int i=-1;i<=1;i++){
        if(pos+i>=1&&pos+i<=m) 
            checkmax(ret,calcb(k,Tb.find(pos+i)));
    }
    printf("%lld\n",ret+ans);
}

signed main()
{
    init();
    while(q--){
        int opt=read();
        if(opt==1){
            int pos=read(),x=read();
            Ta.update(a[pos],-1); suma-=a[pos]; sta.erase(sta.lower_bound(a[pos]));
            a[pos]=x; 
            Ta.update(a[pos],1); suma+=a[pos]; sta.insert(a[pos]);
        }
        else if(opt==2){
            int pos=read(),x=read();
            Tb.update(b[pos],-1); sumb-=b[pos]; stb.erase(stb.lower_bound(b[pos]));
            b[pos]=x;
            Tb.update(b[pos],1); sumb+=b[pos]; stb.insert(b[pos]);
        }
        else{
            int x=read();
            solve(x);
        }
        Min=min(*stb.begin(),*sta.begin());
    }
    return 0;
}