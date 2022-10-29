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
int vis[N],bl[N],n;
void ask(vector<int> v){
    printf("%d ",sz(v));
    for(auto &u : v) printf("%d ",u),vis[u]=1;
    puts("");
    fflush(stdout);
}

vector<int> v;
int mx=0,pos;
bool check(){
    v.clear();
    int cnt=0;
    for(int i=1;i<=n;i++) if(bl[i]&&!vis[i]){
        cnt++; v.push_back(i);
        if(cnt==pos) return 1;
    }
    return 0;
}

int main()
{
    n=read();
    if(n<=3){
        cout<<0<<endl;
        return 0;
    }
    for(int k=2;k<=n-2;k++){
        int tmp=n-(k-1)-n/k-(n%k!=0);
        if(tmp>mx) mx=tmp,pos=k;
    }
    for(int i=1;i<n;i++) if(i%pos) bl[i]=1;
    while(check()){
        ask(v);
        int T=pos,x=read();
        while(T--){
            vis[x]=0; x=x%n+1;
        }
    }
    // int ans=0;
    // for(int i=1;i<=n;i++) ans+=vis[i]; outln(ans);
    cout<<0<<endl;
    return 0;
}