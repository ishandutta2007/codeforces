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
int n,k,cnt=0,a[N],bl[N];
const int B=100001;
namespace FFT{
    int rev[N<<4],G[N<<4],IG[N<<4];
    int init(int n){
        int len=1; while(len<n) len<<=1;
        rev[0]=0;
        for(int i=1;i<len;i++) rev[i]=(rev[i>>1]>>1)+(i&1 ? len>>1 : 0);
        for(int i=1;i<=len;i<<=1){
            G[i]=qpow(3,(MOD-1)/i);
            IG[i]=qpow(G[i],MOD-2);
        }
        return len;
    }
    void ntt(int *a,int len,int flag){
        for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int h=1;h<len;h<<=1){
            int wn=(flag==1 ? G[h<<1] : IG[h<<1]);
            for(int i=0;i<len;i+=(h<<1)){
                int w=1,tmp1,tmp2;
                for(int j=i;j<i+h;j++,Mul(w,wn)){
                    tmp1=a[j]; tmp2=mul(a[j+h],w);
                    a[j]=add(tmp1,tmp2); a[j+h]=sub(tmp1,tmp2);
                }
            }
        }
        if(flag==-1){
            int invlen=qpow(len,MOD-2);
            for(int i=0;i<len;i++) Mul(a[i],invlen);
        }
    }
}

int f[N<<4];
int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++) a[i]=read();
    int fin;
    for(int i=1;i<=n;i++){
        if(bl[i]) continue;
        int j=i+1; fin=i;
        while(a[j]==a[i]&&j<=n) bl[j]=1,j++,cnt++;
    }
    n-=cnt;
    if(a[fin]==a[1]&&fin!=1) n--,cnt++;
    if(n==1){
        puts("0");
        return 0;
    }
    int len=FFT::init(3*n);
    f[0]=1; f[1]=k-2; f[2]=1;
    FFT::ntt(f,len,1);
    for(int i=0;i<len;i++) f[i]=qpow(f[i],n);
    FFT::ntt(f,len,-1);
    int ans=0;
    for(int i=n+1;i<=n*3;i++) Add(ans,f[i]);
    cout<<mul(ans,qpow(k,cnt))<<endl;
    return 0;
}