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
const int N=200005;
int n;
struct node{
    int x,y;
    bool operator < (const node &rhs) const{
        return min(x,y)>min(rhs.x,rhs.y);
    }
}a[N];
void GG(){puts("-1"); exit(0);}
int col[N],ans=inf;
int out[N];
set<pii> st;
int fa[N],cnt[N][2],sz[N][2];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    sort(a+1,a+n+1);
    int mx=min(a[1].x,a[1].y);
    for(int i=1;i<=n;i++) if(mx>max(a[i].x,a[i].y)) GG();
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i].x<a[i].y) col[i]=0;
        else swap(a[i].x,a[i].y),col[i]=1;
        //out(i); out(a[i].x); out(a[i].y); outln(col[i]);
    }
    for(int i=1;i<=n;i++) fa[i]=i,sz[i][col[i]]=1;
    for(int i=1;i<=n;i++){
        if(!st.empty()&&a[i].y>st.begin()->first){
            out[i]=1; //outln(i);
            auto itt=st.lower_bound(mk(a[i].y,i));
            vector<pii> used; 
            auto it2=st.begin(),it=it2;
            for(;it!=itt;it++){
                if(out[it->second]) GG();     
                if(it!=it2) used.push_back(*it);
            }
            for(auto &u : used){
                fa[u.second]=it2->second; 
                sz[it2->second][0]+=sz[u.second][0];
                sz[it2->second][1]+=sz[u.second][1];
                cnt[it2->second][0]+=cnt[u.second][0];
                cnt[it2->second][1]+=cnt[u.second][1];
                st.erase(u);
            }
            cnt[it2->second][col[i]]++;
        }
        st.insert(mk(a[i].y,i));
    }
    int ret=0;
    for(int i=1;i<=n;i++) if(!out[i]&&fa[i]==i){
        ret+=min(sz[i][0]+cnt[i][1],sz[i][1]+cnt[i][0]);
    }
    cout<<ret<<endl;
    return 0;
}