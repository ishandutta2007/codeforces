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
const int N=500005;
const int M=1005;
int ca,cb,n,ns,nt,dp[N],r[N];
char s[N],S[N],T[N]; int nxt[N];
int KMP(){
    memset(nxt,0,sizeof(nxt));
    for(int i=1;i<ns;i++){
        int j=nxt[i];
        while(j&&S[i+1]!=S[j+1]) j=nxt[j];
        if(S[i+1]==S[j+1]) j++;
        nxt[i+1]=j;
    }
    int ret=0;
    for(int i=0,j=0;i<nt;i++){
        while(j&&S[j+1]!=T[i+1]) j=nxt[j];
        if(S[j+1]==T[i+1]) j++;
        checkmax(ret,j);
        if(j==ns) j=nxt[j];
    }
    return ret;
}

int main()
{
    n=read(); ca=read(),cb=read();
    scanf("%s",s+1);
    for(int i=2;i<=n;i++){
        ns=0,nt=0; nt=i-1;
        for(int j=1;j<i;j++) T[j]=s[j];
        for(int j=i;j<=n;j++) S[++ns]=s[j];
        r[i]=KMP()+i-1;
        // out(i); outln(r[i]);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[1]=ca;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=r[i+1];j++) checkmin(dp[j],dp[i]+cb);
        checkmin(dp[i+1],dp[i]+ca);
    }
    cout<<dp[n]<<endl;
    return 0;
}