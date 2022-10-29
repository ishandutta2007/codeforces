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
const int N=300005;
const int M=1000005;
int T,n,m;
int a[N],t1[M],t2[M];
void process(int &x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            int cnt=0;
            while(x%i==0) x/=i,cnt++;
            cnt%=2; if(cnt) x*=i;
        }
    }
}

int main()
{
    T=read();
    while(T--){
        n=read(); for(int i=1;i<=n;i++) a[i]=read(),process(a[i]);
        for(int i=1;i<=n;i++) t1[a[i]]++,t2[a[i]]++;
        for(int i=1;i<=n;i++) if(t2[a[i]]&&a[i]!=1){
            if(t2[a[i]]%2==0) t2[1]+=t2[a[i]],t2[a[i]]=0;
        }
        int mx1=0,mx2=0;
        for(int i=1;i<=n;i++) checkmax(mx1,t1[a[i]]),checkmax(mx2,t2[a[i]]);
        checkmax(mx2,t2[1]);
        m=read();
        while(m--){
            ll x; scanf("%lld",&x);
            if(!x) printf("%d\n",mx1);
            else printf("%d\n",mx2);
        }
        for(int i=1;i<=n;i++) t1[a[i]]=0,t2[a[i]]=0; t2[1]=0;
    }
    return 0;
}