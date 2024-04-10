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
int MOD=998244353;
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
const int N=270005;
ll MMOD;
int n,k,len,m;
int cnt[N],fac[N],ifac[N];
ll f[19][N],h[19][N],g[19][N];
void FWT(ll *a){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++) a[j+h]+=a[j];
        }
    }
    for(int i=0;i<len;i++) a[i]=(a[i]%MOD+MOD)%MOD;
}
void IFWT(ll *a){
    for(int h=1;h<len;h<<=1){
        for(int i=0;i<len;i+=(h<<1)){
            for(int j=i;j<i+h;j++) a[j+h]-=a[j];
        }
    }
    for(int i=0;i<len;i++) a[i]=(a[i]%MOD+MOD)%MOD;
}

void ksm(int k){
    for(int i=0;i<len;i++) h[0][i]=1;
    while(k){
        if(k&1){
            memset(g,0,sizeof(g));
            for(int i=0;i<=m;i++){
                for(int j=0;j+i<=m;j++){
                    ll *w1=&g[i+j][0],*w2=&f[i][0],*w3=&h[j][0];
                    for(int c=0;c<len;c++){
                        *w1+=(*w2)*(*w3);
                        if((*w1)>=MMOD) (*w1)-=MMOD;
                        w1++; w2++; w3++;
                    }
                }
            }
            for(int i=0;i<=m;i++) for(int j=0;j<len;j++) h[i][j]=g[i][j]%MOD;
        }
        memset(g,0,sizeof(g));
        for(int i=0;i<=m;i++){
            for(int j=0;j+i<=m;j++){
                ll *w1=&g[i+j][0],*w2=&f[i][0],*w3=&f[j][0];
                for(int c=0;c<len;c++){
                    *w1+=(*w2)*(*w3);
                    if((*w1)>=MMOD) (*w1)-=MMOD;
                    w1++; w2++; w3++;
                }
            }
        }
        for(int i=0;i<=m;i++) for(int j=0;j<len;j++) f[i][j]=g[i][j]%MOD;
        k>>=1;
    }
}

int main()
{
    n=read(); k=read(); MOD=read(); MMOD=8ll*MOD*MOD;
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2); 
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    len=1; m=0; while(len<=n) len<<=1,m++;
    for(int i=0;i<len;i++) cnt[i]=__builtin_popcount(i);
    for(int i=0;i<len;i++) f[cnt[i]][i]=ifac[i];
    for(int i=0;i<=m;i++) FWT(f[i]);
    ksm(k); 
    for(int i=0;i<=m;i++) IFWT(h[i]);
    if(n&1) cout<<qpow(k,n)<<endl;
    else cout<<sub(qpow(k,n),mul(fac[n],h[cnt[n]][n]))<<endl;
    return 0;
}