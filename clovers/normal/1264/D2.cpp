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
const int N=1000005;
int n,fac[N],ifac[N],pre1[N],suf1[N],pre2[N],suf2[N]; char s[N];
int sum1[N],sum2[N],cnt;
int C(int n,int m){
    if(n<m) return 0;
    return mul(fac[n],mul(ifac[n-m],ifac[m]));
}

int main()
{
    scanf("%s",s+1); n=strlen(s+1);
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    ifac[n]=qpow(fac[n],MOD-2);
    for(int i=n-1;i>=0;i--) ifac[i]=mul(ifac[i+1],i+1);
    for(int i=1;i<=n;i++){
        pre1[i]=pre1[i-1]; pre2[i]=pre2[i-1];
        pre1[i]+=(s[i]=='('); pre2[i]+=(s[i]=='?');
    }
    for(int i=n;i>=1;i--){
        suf1[i]=suf1[i+1]; suf2[i]=suf2[i+1];
        suf1[i]+=(s[i]==')'); suf2[i]+=(s[i]=='?');
    }
    cnt=pre2[n];
    for(int i=0;i<=n;i++){
        sum1[i]=add(sum1[i-1],C(cnt,i));
        sum2[i]=add(sum2[i-1],C(cnt-1,i));
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(s[i]!=')'){
        if(s[i]=='?'&&suf2[i+1]+suf1[i+1]-pre1[i]-1>=0) 
            Add(ans,sum2[suf2[i+1]+suf1[i+1]-pre1[i]-1]);
        if(s[i]=='('&&suf2[i+1]+suf1[i+1]-pre1[i]>=0) 
            Add(ans,sum1[suf2[i+1]+suf1[i+1]-pre1[i]]);
    }
    cout<<ans<<endl;
    return 0;
}