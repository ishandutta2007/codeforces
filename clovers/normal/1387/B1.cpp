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
int n,mat[N],rev[N],ans=0;
vector<int> v[N];
void dfs(int u,int f){
    vector<int> seq;
    for(auto &to : v[u]) if(to!=f){
        dfs(to,u);
        if(!mat[to]) seq.push_back(to);
    }
    if(!seq.empty()){
        ans+=2*sz(seq); seq.push_back(u);
        for(int i=0;i<sz(seq);i++){
            mat[seq[i]]=seq[(i+1)%sz(seq)];
            rev[seq[(i+1)%sz(seq)]]=seq[i];
        }
    }
    else if(f==-1){
        ans+=2;
        int to=v[u][0];
        mat[rev[to]]=u; mat[u]=to;
    }
}

int main()
{
    n=read(); 
    for(int i=1;i<n;i++){
        int x=read(),y=read();
        v[x].push_back(y); v[y].push_back(x);
    }
    dfs(1,-1);
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) printf("%d ",mat[i]);
    return 0;
}