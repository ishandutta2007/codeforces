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
inline ll read(){
    ll x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=200005;
ll a[N]; int cnt=0;
struct Basis{
    ll a[35];
    void insert(ll x){
        for(int i=34;i>=0;i--) if(x>>i&1){
            if(!a[i]){a[i]=x; cnt++; break;}
            else x^=a[i];
        }
    }
}B;
int top=0,ans,b[40],ret[N],n,m;
int f[1<<17],g[20][1<<17],h[1<<17],len;
void FWT(int *a,int flag,int len){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++){
                int tmp1=add(a[j],a[j+h]),tmp2=sub(a[j],a[j+h]);
                a[j]=tmp1; a[j+h]=tmp2;
            }
        }
    }
    if(flag==-1){
        int invlen=qpow(len,MOD-2);
        for(int i=0;i<len;i++) Mul(a[i],invlen);
    }
}

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read(),B.insert(a[i]);
    ans=qpow(2,n-cnt);
    for(int i=0;i<35;i++) a[i]=B.a[i];
    int len=(1<<17);
    for(int S=1;S<len;S++){
        int flag=1,tmp=0;
        for(int i=0;i<17;i++) if(S>>i&1){
            if(a[i]) tmp^=a[i];
            else flag=0;
        }
        if(!flag) continue;
        int tt=__builtin_popcount(tmp);
        f[tmp]++; ret[tt]++;
    }
    int full=(1<<18);
    for(int S=1;S<full;S++){
        ll flag=1,tmp=0;
        for(int i=0;i<18;i++) if(S>>i&1){
            if(a[i+17]) tmp^=a[i+17];
            else flag=0;
        }
        if(!flag) continue;
        ret[__builtin_popcountll(tmp)]++;
        int num=0;
        for(int i=17;i<=34;i++) if(tmp>>i&1) num++,tmp^=(1ll<<i);
        g[num][tmp]++;
    }
    FWT(f,1,len);
    for(int i=0;i<=18;i++){
        FWT(g[i],1,len);
        for(int S=0;S<len;S++) h[S]=mul(f[S],g[i][S]);
        FWT(h,-1,len);
        for(int S=0;S<len;S++) Add(ret[__builtin_popcount(S)+i],h[S]);
    }
    ret[0]=1;
    for(int i=0;i<=m;i++) Mul(ret[i],ans);
    for(int i=0;i<=m;i++) printf("%d ",ret[i]);
    return 0;
}