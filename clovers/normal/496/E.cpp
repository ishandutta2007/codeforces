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
const int N=400005;
struct Person{int l,r,ti;}P[N];
struct Music{int l,r;}a[N];
struct node{
    int r,ti,id;
    bool operator < (const node &rhs) const{
        if(r==rhs.r) return id<rhs.id;
        return r<rhs.r;
    }
};
multiset<node> st;
vector<pii> v1[N],v2[N];
int n,top=0,val[N],m,ans[N];

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        a[i].l=read(),a[i].r=read();
        val[++top]=a[i].l; val[++top]=a[i].r;
    }
    m=read();
    for(int i=1;i<=m;i++){
        P[i].l=read(); P[i].r=read(); P[i].ti=read();
        val[++top]=P[i].l, val[++top]=P[i].r;
    }
    sort(val+1,val+top+1);
    top=unique(val+1,val+top+1)-val-1;
    for(int i=1;i<=n;i++){
        a[i].l=lower_bound(val+1,val+top+1,a[i].l)-val;
        a[i].r=lower_bound(val+1,val+top+1,a[i].r)-val;
    }
    for(int i=1;i<=m;i++){
        P[i].l=lower_bound(val+1,val+top+1,P[i].l)-val;
        P[i].r=lower_bound(val+1,val+top+1,P[i].r)-val;
    }
    for(int i=1;i<=n;i++) v1[a[i].l].push_back(mk(a[i].r,i));
    for(int i=1;i<=m;i++) v2[P[i].l].push_back(mk(P[i].r,i));
    for(int i=1;i<=top;i++){
        for(auto &u : v2[i]){
            st.insert({u.first,P[u.second].ti,u.second});
        }
        for(auto &u : v1[i]){
            node tmp={u.first,-1,-1};
            auto it=st.lower_bound(tmp);
            if(it==st.end()){puts("NO"); return 0;}
            st.erase(it);
            ans[u.second]=it->id;
            tmp=*it; tmp.ti--;
            if(tmp.ti) st.insert(tmp);
        }
    }
    puts("YES");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
    return 0;
}