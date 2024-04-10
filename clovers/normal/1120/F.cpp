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
int n,c,d,t[N],typ[N];
char s[2]; ll ans=INF,val[N];

int main()
{
    n=read(); c=read(); d=read();
    for(int i=1;i<=n;i++){
        t[i]=read(); scanf("%s",s);
        typ[i]=(s[0]=='P');
    }
    t[n+1]=read();
    int nxt0=n+1,nxt1=n+1;
    for(int i=n;i>=1;i--){
        val[i]=val[i+1];
        if(i!=1&&typ[i]!=typ[i-1]){
            if(typ[i]==0) val[i]+=(t[nxt1]-t[i])*c,nxt0=i;
            else val[i]+=(t[nxt0]-t[i])*c,nxt1=i;
        }
        else if(typ[i]==1) val[i]+=min(d,(t[nxt0]-t[i])*c);
        else val[i]+=min(d,(t[nxt1]-t[i])*c);
        // out(i); outln(val[i]);
    }
    ans=1ll*n*d;
    for(int i=1;i<=n;i++) checkmin(ans,val[i]+1ll*(i-1)*d);
    cout<<ans<<endl;
    return 0;
}