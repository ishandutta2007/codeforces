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
const int M=100005;
int T,n,m,a[N][N][3],ans[N][N],f[3],b[3],p[3];
char opt[M];

void solve(){
    int revh=0,revs=0;
    for(int i=0;i<=2;i++) f[b[i]=i]=0;
    n=read(); m=read();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j][0]=i; a[i][j][1]=j; 
            a[i][j][2]=read()-1;
        }
    }
    scanf("%s",opt+1);
    for(int i=1;i<=m;i++){
        if(opt[i]=='R') f[1]++;
        else if(opt[i]=='L') f[1]--;
        else if(opt[i]=='D') f[0]++;
        else if(opt[i]=='U') f[0]--;
        else if(opt[i]=='I') swap(b[1],b[2]),swap(f[1],f[2]);
        else swap(b[0],b[2]),swap(f[0],f[2]);
    }
    for(int i=0;i<=2;i++) f[i]=(f[i]%n+n)%n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int t=0;t<=2;t++) p[t]=((a[i][j][b[t]]+f[t])%n+n)%n;
            ans[p[0]][p[1]]=p[2];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",ans[i][j]+1);
        puts("");
    }
}

int main()
{
    T=read();
    while(T--){solve();}
    return 0;
}