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
const int N=200005;
int T,n,deg[N];
vector<int> v[N];

int main()
{
    T=read();
    while(T--){
        n=read(); 
        for(int i=1;i<=n;i++) deg[i]=0,v[i].clear();
        for(int i=1;i<=n;i++){
            int k=read(); deg[i]=k;
            while(k--) v[read()].push_back(i);
        }
        set<int> st;
        for(int i=1;i<=n;i++) if(!deg[i]) st.insert(i);
        vector<int> seq; int pre=0;
        while(!st.empty()){
            auto it=st.lower_bound(pre); 
            if(it==st.end()) it=st.begin();
            int u=*it; st.erase(it); pre=u;
            seq.push_back(u);
            for(auto &to : v[u]) if(!--deg[to]) st.insert(to);
        }
        int ok=1;
        for(int i=1;i<=n;i++) if(deg[i]) ok=0;
        if(!ok) puts("-1");
        else{
            int ans=1;
            for(int i=1;i<n;i++) ans+=(seq[i]<seq[i-1]);
            printf("%d\n",ans);
        }
    }
    return 0;
}