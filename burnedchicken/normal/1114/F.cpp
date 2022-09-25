#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=400005;

//i_am_noob
//#define wiwihorz  
int n,q,a[maxn],b[maxn],lpd[305],bit[62][maxn],c[62],val[4*maxn],tag[4*maxn];
vector<int> pr;

inline int Pow(int a, int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD,b>>=1;
    }
    return res;
}

void chkmax(int k, int p, int x){for(p++; p<maxn; p+=p&-p) bit[k][p]=max(bit[k][p],x);}

int getmax(int k, int r){
    int res=-1;
    for(r++; r; r-=r&-r) res=max(res,bit[k][r]);
    return res;
}

void pull(int k){val[k]=(val[k<<1]*val[k<<1|1])%MOD;}

void push(int k, int l, int r){
    if(l!=r){
        int mid=l+r>>1;
        val[k<<1]=val[k<<1]*Pow(tag[k],mid-l+1)%MOD,val[k<<1|1]=val[k<<1|1]*Pow(tag[k],r-mid)%MOD;
        tag[k<<1]=tag[k<<1]*tag[k]%MOD,tag[k<<1|1]=tag[k<<1|1]*tag[k]%MOD;
    }
    tag[k]=1;
}

void build(int k, int l, int r){
    tag[k]=1;
    if(l==r){
        val[k]=a[l];
        return;
    }
    int mid=l+r>>1;
    build(k<<1,l,mid),build(k<<1|1,mid+1,r);
    pull(k);
}

void mul(int k, int l, int r, int ql, int qr, int x){
    if(r<ql||l>qr) return;
    if(ql<=l&&qr>=r){
        val[k]=val[k]*Pow(x,r-l+1)%MOD,tag[k]=tag[k]*x%MOD;
        return;
    }
    push(k,l,r);
    int mid=l+r>>1;
    mul(k<<1,l,mid,ql,qr,x),mul(k<<1|1,mid+1,r,ql,qr,x);
    pull(k);
}

int pro(int k, int l, int r, int ql, int qr){
    if(r<ql||l>qr) return 1;
    if(ql<=l&&qr>=r) return val[k];
    push(k,l,r);
    int mid=l+r>>1;
    return pro(k<<1,l,mid,ql,qr)*pro(k<<1|1,mid+1,r,ql,qr)%MOD;
}

void hhhhauraorz(){
    lpd[0]=lpd[1]=-1;
    rep2(i,2,301){
        if(!lpd[i]) lpd[i]=i,pr.pb(i);
        for(auto p: pr){
            if(p*i>300) break;
            lpd[p*i]=p;
            if(i%p==0) break;
        }
    }
    rep(sz(pr)) c[i]=(pr[i]-1)*Pow(pr[i],MOD-2)%MOD;
    cin >> n >> q;
    rep(n) cin >> a[i];
    build(1,0,n-1);
    rep(62) memset(bit[i],-1,sizeof bit[i]);
    rep(n) rep1(j,sz(pr)) if(a[i]%pr[j]==0) chkmax(j,i,i);
    while(q--){
        string str;
        int l,r,x;
        cin >> str >> l >> r;
        l--,r--;
        if(str[0]=='M'){
            cin >> x;
            mul(1,0,n-1,l,r,x);
            rep(62) if(x%pr[i]==0) chkmax(i,l,r);
            continue;
        }
        else{
            int res=pro(1,0,n-1,l,r);
            rep(62) if(getmax(i,r)>=l) res=res*c[i]%MOD;
            print(res);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) hhhhauraorz();
    return 0;
}