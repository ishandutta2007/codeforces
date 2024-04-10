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
const int N=8192;
const int M=1000005;
int n,a[M],mp[N+1][N+1];
vector<int> v[N];

int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    for(int i=0;i<N;i++) mp[0][i]=1,v[i].push_back(0);
    for(int i=1;i<=n;i++){
        vector<int> v2;
        for(auto &u : v[a[i]]){
            int to=(u^a[i]);
            if(!mp[to][a[i]]){
                v2.push_back(to);
                for(int j=a[i]+1;j<N;j++){
                    if(mp[to][j]) break;
                    mp[to][j]=1; v[j].push_back(to);
                }
            }
        }
        v[a[i]].clear(); v[a[i]]=v2;
    }
    vector<int> ans;
    for(int i=0;i<N;i++) if(mp[i][N-1]) ans.push_back(i);
    printf("%d\n",sz(ans));
    for(auto &u : ans) printf("%d ",u);
    return 0;
}