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
const int N=1005;
int n,m,a[N][N],mx[N][N],mi[N][N];
int val[N],top=0;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) a[i][j]=read();
    }
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=1;j<=m;j++) val[++top]=a[i][j];
        sort(val+1,val+top+1); top=unique(val+1,val+top+1)-val-1;
        for(int j=1;j<=m;j++){
            int pos=lower_bound(val+1,val+top+1,a[i][j])-val;
            mx[i][j]=top-pos; mi[i][j]=pos-1;
        }
    }
    for(int j=1;j<=m;j++){
        top=0;
        for(int i=1;i<=n;i++) val[++top]=a[i][j];
        sort(val+1,val+top+1); top=unique(val+1,val+top+1)-val-1;
        for(int i=1;i<=n;i++){
            int pos=lower_bound(val+1,val+top+1,a[i][j])-val;
            checkmax(mx[i][j],top-pos); checkmax(mi[i][j],pos-1);
        }
    }   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) printf("%d ",mx[i][j]+mi[i][j]+1);
        puts("");
    }
    return 0;
}