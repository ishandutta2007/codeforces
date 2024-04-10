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
const int N=505;
int T,n,a[N<<1][N],vis[N<<1],num[N][N];
int ret,rest;
vector<int> ans;

void del(int pos){
    rest--; vis[pos]=1;
    for(int j=1;j<=n;j++) num[j][a[pos][j]]--;
}

void insert(int pos){
    ans.push_back(pos); del(pos);
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n+n;i++) if(!vis[i]&&a[i][j]==a[pos][j]) del(i);
    }
}

void solve(){
    n=read(); ans.clear();
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n+n;i++)
        for(int j=1;j<=n;j++) a[i][j]=read(),num[j][a[i][j]]++;
    ret=1,rest=2*n;
    while(rest){
        int p1=-1,p2=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) if(num[i][j]==1) p1=i,p2=j;
        }
        if(p1==-1){
            Mul(ret,2); 
            for(int i=1;i<=n+n;i++) if(!vis[i]){insert(i); break;}
            continue;
        }
        for(int i=1;i<=n+n;i++) if(a[i][p1]==p2&&!vis[i]){
            insert(i); break;
        }
    }
    printf("%d\n",ret);
    for(auto &u : ans) printf("%d ",u); puts("");
}

int main()
{
    T=read();
    while(T--){solve();}
    return 0;
}