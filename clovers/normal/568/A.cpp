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
const int N=1200005;
int n=1200000,prime[N],tot=0,bl[N],pi[N],rub[N];
bool check(int x){
    vector<int> v; v.clear();
    while(x) v.push_back(x%10),x/=10;
    int cnt=sz(v);
    for(int i=0;i<cnt;i++) if(v[i]!=v[cnt-i-1]) return 0;
    return 1;
}
void init(){
    for(int i=1;i<=n;i++) rub[i]=(rub[i-1]+check(i));
    for(int i=2;i<=n;i++){
        pi[i]=pi[i-1];
        if(!bl[i]) pi[i]++,prime[++tot]=i;
        for(int j=1;j<=tot;j++){
            if(i*prime[j]>n) break;
            bl[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    init();
    int p=read(),q=read();
    int ans=0;
    for(int i=1;i<=n;i++){
        if(p*rub[i]>=q*pi[i]) ans=i;
    }
    cout<<ans<<endl;
    return 0;
}