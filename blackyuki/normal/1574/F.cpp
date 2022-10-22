#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define pb emplace_back
#define lb(v,k) (lower_bound(all(v),(k))-v.begin())
#define ub(v,k) (upper_bound(all(v),(k))-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
#define all(a) a.begin(),a.end()
#define rsort(a) {sort(all(a));reverse(all(a));}
#define dupli(a) {sort(all(a));a.erase(unique(all(a)),a.end());}
#define popcnt __builtin_popcountll
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vvvvi=vector<vvvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const ll INF=1001001001;
const ll mod=998244353;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void outset(T s){auto itr=s.begin();while(itr!=s.end()){if(itr!=s.begin())cout<<' ';cout<<*itr;itr++;}cout<<'\n';}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){ll res=1;a%=mod;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
#define MOD 998244353
#define root 3
 
unsigned int add(const unsigned int x, const unsigned int y)
{
    return (x + y < MOD) ? x + y : x + y - MOD;
}
 
unsigned int sub(const unsigned int x, const unsigned int y)
{
    return (x >= y) ? (x - y) : (MOD - y + x);
}
 
unsigned int mul(const unsigned int x, const unsigned int y)
{
    return (unsigned long long)x * y % MOD;
}
 
unsigned int mod_pow(unsigned int x, unsigned int n)
{
    unsigned int res = 1;
    while(n > 0){
        if(n & 1){ res = mul(res, x); }
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}
 
unsigned int inverse(const unsigned int x)
{
    return mod_pow(x, MOD - 2);
}
 
void ntt(vi& a, const bool rev = false)
{
    unsigned int i, j, k, l, p, q, r, s;
    const unsigned int size = a.size();
    if(size == 1) return;
    vi b(size);
    r = rev ? (MOD - 1 - (MOD - 1) / size) : (MOD - 1) / size;
    s = mod_pow(root, r);
    vector<unsigned int> kp(size / 2 + 1, 1);
    for(i = 0; i < size / 2; ++i) kp[i + 1] = mul(kp[i], s);
    for(i = 1, l = size / 2; i < size; i <<= 1, l >>= 1){
        for(j = 0, r = 0; j < l; ++j, r += i){
            for(k = 0, s = kp[i * j]; k < i; ++k){
                p = a[k + r], q = a[k + r + size / 2];
                b[k + 2 * r] = add(p, q);
                b[k + 2 * r + i] = mul(sub(p, q), s);
            }
        }
        swap(a, b);
    }
    if(rev){
        s = inverse(size);
        for(i = 0; i < size; i++){ a[i] = mul(a[i], s); }
    }
}

vi convolute(const vi& a, const vi& b)
{
    const ll size = (ll)a.size() + (ll)b.size() - 1;
    ll t = 1;
    while(t < size){ t <<= 1; }
    vi A(t, 0), B(t, 0);
    for(ll i = 0; i < (ll)a.size(); i++){ A[i] = a[i]; }
    for(ll i = 0; i < (ll)b.size(); i++){ B[i] = b[i]; }
    ntt(A), ntt(B);
    for (ll i = 0; i < t; i++){ A[i] = mul(A[i], B[i]); }
    ntt(A, true);
    A.resize(size);
    return A;
}
class UF{
    vi data;stack<P> st;
public:
    UF(ll n){
        data=vi(n,1);
    }
    bool merge(ll x,ll y,bool undo=false){
        x=rt(x);y=rt(y);
        if(data[x]>data[y])swap(x,y);
        if(undo){st.emplace(y,data[y]);st.emplace(x,data[x]);}
        if(x==y)return false;
        data[y]+=data[x];data[x]=-y;
        return true;
    }
    ll rt(ll i){if(data[i]>0)return i;return rt(-data[i]);}
    ll getsize(ll i){return data[rt(i)];}
    bool same(ll a,ll b){return rt(a)==rt(b);}
    void undo(){rep(i,2){data[st.top().fi]=st.top().se;st.pop();}}
};
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m,k;cin>>k>>m>>n;
    vi nxt(n,-1),prev(n,-1),cnt(n);
    vb bad(n,false);
    UF uf(n);
    rep(i,k){
        ll t;cin>>t;
        vi v(t);
        rep(j,t)cin>>v[j];
        rep(j,t)v[j]--;
        bool ok=true;
        rep(j,t-1){
            if(nxt[v[j]]!=-1&&nxt[v[j]]!=v[j+1])ok=false;
            nxt[v[j]]=v[j+1];
            if(prev[v[j+1]]!=-1&&prev[v[j+1]]!=v[j])ok=false;
            prev[v[j+1]]=v[j];
        }
        rep(j,t-1)uf.merge(v[j],v[j+1]);
        dupli(v);
        if(v.size()!=t||!ok){
            for(ll x:v)bad[x]=true;
        }
    }
    vb ok(n,false);
    rep(i,n)if(bad[i])bad[uf.rt(i)]=true;
    rep(i,n)if(!bad[i]&&nxt[i]==-1&&!bad[uf.rt(i)])ok[uf.rt(i)]=true;
    vi f(m+1);
    rep(i,n)if(uf.rt(i)==i&&ok[i])if(uf.getsize(i)<=m)f[uf.getsize(i)]++;
    vi dp(m+1);
    dp[0]=1;
    function<void(ll,ll)> dfs=[&](ll l,ll r){
        if(l==r)return;
        ll md=(l+r)/2;
        dfs(l,md);
        vi a,b,c;
        REP(i,l,md+1)a.pb(dp[i]);
        rep(i,r-l+1)b.pb(f[i]);
        c=convolute(a,b);
        REP(i,md+1,r+1)dp[i]+=c[i-l];
        REP(i,md+1,r+1)dp[i]%=mod;
        dfs(md+1,r);
    };dfs(0,m);
    out(dp[m]);
}