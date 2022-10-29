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
int MOD=998244353;
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
const int N=105;
int n,m,k,f[N][N][N];
int C[N][N],fac[N];
int DP(int x,int y,int z){
    if(z&&z+y-1>x) return 0;
    if(f[x][y][z]!=-1) return f[x][y][z];
    if(y==1){
        if(z!=1) return f[x][y][z]=0;
        return fac[x];
    }
    if(x==1) return f[x][y][z]=(!z);
    int ret=0;
    for(int i=2;i<x;i++){
        for(int j=0;j<=z/2;j++) Add(ret,mul(C[x-1][i-1],mul(DP(i-1,y-1,j),DP(x-i,y-1,z-j))));
    }
    Mul(ret,2);
    if(z%2==0) for(int i=2;i<x;i++) Sub(ret,mul(C[x-1][i-1],mul(DP(i-1,y-1,z/2),DP(x-i,y-1,z/2))));
    Add(ret,mul(2,DP(x-1,y-1,z)));
    return f[x][y][z]=ret;
}

int main()
{
    n=read(); m=read(); k=read(); MOD=read();
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++) C[i][j]=add(C[i-1][j],C[i-1][j-1]);
    }
    fac[0]=1; for(int i=1;i<=n;i++) fac[i]=mul(fac[i-1],i);
    memset(f,-1,sizeof(f));
    cout<<DP(n,m,k);
    return 0;
}