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
const ll INF=(ll)2e18;
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
const int N=1005;
int GG(){puts("-1"); exit(0);}
int n,m,cnt1=0,cnt2=0;
char s[N][N];

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    int ans=0,prel=m+1,prer=-1;
    for(int i=1;i<=n;i++){
        int l=m+1,r=-1;
        for(int j=1;j<=m;j++) if(s[i][j]=='#') checkmin(l,j),checkmax(r,j);
        for(int j=l;j<=r;j++) if(s[i][j]=='.') GG();
        if(l>m) cnt1++;
        else if(prer<l||prel>r) ans++;
        prel=l; prer=r;
    }
    prel=n+1,prer=-1;
    for(int j=1;j<=m;j++){
        int l=n+1,r=-1;
        for(int i=1;i<=n;i++) if(s[i][j]=='#') checkmin(l,i),checkmax(r,i);
        for(int i=l;i<=r;i++) if(s[i][j]=='.') GG();
        if(l>n) cnt2++;
        prel=l; prer=r;
    }
    if((!cnt1&&cnt2)||(!cnt2&&cnt1)) GG();
    cout<<ans<<endl;
    return 0;
}