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
const int N=5005;
const int M=100001;
int bl[M],prime[M],tot=0;
void init(){
    for(int i=2;i<M;i++){
        if(!bl[i]) prime[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(i*prime[j]>M-1) break;
            bl[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int n,m,a[N],b[N],ans=0;
int calc(int x){
    int now=0,j=1;
    for(int i=1;prime[i]*prime[i]<=x;i++){
        int u=prime[i];
        if(x%u==0){
            while(b[j]<u&&j<m) j++;
            int bl=(b[j]==u ? -1 : 1);
            while(x%u==0) x/=u,now+=bl;
        }
    }
    if(x!=1){
        while(b[j]<x&&j<m) j++;
        now+=(b[j]==x ? -1 : 1);
    }
    return now;
}

int main()
{
    init();
    n=read(); m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    for(int i=1;i<=n;i++) ans+=calc(a[i]);
    for(int i=n;i>=1;i--){
        int g=a[1];
        for(int j=2;j<=i;j++) g=__gcd(g,a[j]);
        if(g==1) continue;
        int tmp=calc(g);
        if(tmp<0){
            ans-=tmp*i;
            for(int j=1;j<=i;j++) a[j]/=g;
        }
    }
    cout<<ans<<endl;
    return 0;
}