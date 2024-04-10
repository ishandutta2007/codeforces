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
const int N=105;
int T,n,m,a[N][N],vis[N][N],ret[N][N];
deque<int> v[N];

int main()
{
    T=read();
    while(T--){
        memset(vis,0,sizeof(vis));
        n=read(); m=read();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) a[i][j]=read();
            sort(a[i]+1,a[i]+m+1);
            while(!v[i].empty()) v[i].pop_back();
            for(int j=1;j<=m;j++) v[i].push_back(a[i][j]);
        }
        for(int i=1;i<=m;i++){
            int mi=inf+1,pos;
            for(int j=1;j<=n;j++){
                if(v[j].front()<mi) mi=v[j].front(),pos=j;
            }
            v[pos].pop_front(); ret[pos][i]=mi;
            for(int j=1;j<=n;j++) if(j!=pos){
                ret[j][i]=v[j].back();
                v[j].pop_back();
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) printf("%d ",ret[i][j]);
            puts("");
        }
    }
    return 0;
}