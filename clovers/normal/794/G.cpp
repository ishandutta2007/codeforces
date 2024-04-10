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
const int MOD=1e9+7;
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
const int N=1200005;
char S[N],T[N];
int n,m,fac[N],ifac[N],Sa=0,Sb=0,Ta=0,Tb=0,Sq=0,Tq=0,Base[N];
int lenS,lenT;
int C(int n,int m){
    if(n<m||m<0) return 0;
    return mul(fac[n],mul(ifac[n-m],ifac[m]));
}
bool check(){
    if(lenS!=lenT) return 0;
    for(int i=1;i<=n;i++){
        if((S[i]=='A'&&T[i]=='B')||(S[i]=='B'&&T[i]=='A')) return 0;
    }
    return 1;
}
int f[N],g[N],mu[N],prime[N],bl[N],tot=0;
void init(){
    mu[1]=1;
    for(int i=2;i<=N-1;i++){
        if(!bl[i]) prime[++tot]=i,mu[i]=MOD-1;
        for(int j=1;j<=tot;j++){
            if(i*prime[j]>N-1) break;
            bl[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            mu[i*prime[j]]=(MOD-mu[i])%MOD;
        }
    }
    for(int i=1;i<=N-1;i++) f[i]=Base[i];
    for(int i=1;i<=N-1;i++){
        for(int j=i;j<=N-1;j+=i) Add(g[j],mul(mu[i],f[j/i]));
    }
}
int Z=0;
 
int main()
{
    n=1200000;
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    Base[0]=1; for(int i=1;i<=n+1;i++) Base[i]=mul(Base[i-1],2);
    scanf("%s",S+1); scanf("%s",T+1);
    lenS=strlen(S+1); lenT=strlen(T+1);
    n=max(strlen(S+1),strlen(T+1)); scanf("%d",&m);
    for(int i=1;i<=lenS;i++){
        Sa+=(S[i]=='A'); Sb+=(S[i]=='B'); Sq+=(S[i]=='?');
    }
    for(int i=1;i<=lenT;i++){
        Ta+=(T[i]=='A'); Tb+=(T[i]=='B'); Tq+=(T[i]=='?');
    }
    int ans=0,num=0;
    init();
    for(int i=1;i<=m;i++){
        Add(Z,mul(g[i],mul(m/i,m/i)));
    }
    outln(Z);
    for(int d=-Tq;d<=Sq;d++){//d=i-j
        int A=Sa-Ta+d,B=Tb+Tq-Sb-Sq+d;
        if(1ll*A*B<0||(1ll*A*B==0&&A+B!=0)) continue;
        if(A<0) A=-A,B=-B;
        int tmp2;
        tmp2=C(Sq+Tq,Sq-d);
        if(A+B==0){
            Add(ans,mul(tmp2,Z));
            continue;
        }
        int g=__gcd(A,B); A/=g,B/=g;
        int tmp=m/max(A,B);
        Add(ans,mul(tmp2,sub(Base[tmp+1],2)));
        Add(num,tmp2);
    }
    outln(ans);
    if(check()){
        int cnt=0;
        for(int i=1;i<=n;i++) if(S[i]=='?'&&T[i]=='?') cnt++;
        cnt=qpow(2,cnt);
        int tmp2=mul(sub(Base[m+1],2),sub(Base[m+1],2));
        Add(ans,mul(cnt,sub(tmp2,Z)));
    }
    cout<<ans<<endl;
    return 0;
}