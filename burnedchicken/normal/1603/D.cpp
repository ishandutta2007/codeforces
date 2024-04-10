#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
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
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

struct segment_tree{
    vector<int> val,tag;
    int type;
    constexpr int mid(int l, int r){return l+r>>1;}
    segment_tree(int _siz, int _type){val.resize(4*_siz),tag.resize(4*_siz),type=_type;}
    inline int oper(int i, int j){
        if(type==0) return i+j;
        else if(type==1) return min(i,j);
        else return max(i,j);
    }
    inline int def(){
        if(type==0) return 0;
        else if(type==1) return inf;
        else return -inf;
    }
    void pull(int k){val[k]=oper(val[k<<1],val[(k<<1)+1]);}
    void push(int k, int l, int r){
        if(l!=r){
            if(type){
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=tag[k];
                val[(k<<1)+1]+=tag[k];
            }
            else{
                tag[k<<1]+=tag[k];
                tag[(k<<1)+1]+=tag[k];
                val[k<<1]+=(mid(l,r)-l+1)*tag[k];
                val[(k<<1)+1]+=(r-mid(l,r))*tag[k];
            }
        }
        tag[k]=0;
    }
    void modify(int k, int l, int r, int ql, int qr, int x){
        if(ql<=l&&qr>=r){
            if(type) val[k]+=x;
            else val[k]+=(r-l+1)*x;
            tag[k]+=x;
            return;
        }
        push(k,l,r);
        if(ql<=mid(l,r)) modify(k<<1,l,mid(l,r),ql,qr,x);
        if(qr>mid(l,r)) modify((k<<1)+1,mid(l,r)+1,r,ql,qr,x);
        pull(k);
    }
    int query(int k, int l, int r, int ql, int qr){
        if(ql<=l&&qr>=r) return val[k];
        push(k,l,r);
        int res=def();
        if(ql<=mid(l,r)) res=oper(res,query(k<<1,l,mid(l,r),ql,qr));
        if(qr>mid(l,r)) res=oper(res,query((k<<1)+1,mid(l,r)+1,r,ql,qr));
        return res;
    }
};
template<int maxn>
struct NT{
    vector<int> pr;
    int lpd[maxn];
    NT(){
        pr.clear();
        rep(maxn) lpd[i]=-1;
        rep2(i,2,maxn){
            if(lpd[i]==-1) lpd[i]=i,pr.pb(i);
            for(auto p: pr){
                if(p*i>=maxn) break;
                lpd[p*i]=p;
                if(i%p==0) break;
            }
        }
    }
    inline bool isp(int x){return lpd[x]==x;}
    signed fac_cnt(signed x){
        assert(x>=1&&x<maxn);
        signed res=1,lst=0,cur=0;
        while(x>1){
            signed p=lpd[x];
            if(p!=lst) res*=cur+1,cur=0;
            cur++;
            lst=p;
            x/=p;
        }
        return res*(cur+1);
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=100005,maxm=17,maxk=30;
    
//i_am_noob
//#define wiwihorz  
ll dp[maxm][maxn],phi[maxn],cnt[maxk+5][maxn];
NT<maxn> nt;
vector<int> factors[maxn];

void orzck(){
    rep2(i,1,maxn) dp[1][i]=1ll*i*(i-1)/2;
    rep2(i,1,maxn){
        vector<int> vec;
        int x=i;
        while(x>1){
            vec.pb(nt.lpd[x]);
            x/=nt.lpd[x];
        }
        vec.resize(unique(all(vec))-vec.begin());
        phi[i]=i;
        for(auto p: vec) phi[i]/=p,phi[i]*=p-1;
    }
    rep2(i,2,maxn) for(int j=i*2; j<maxn; j+=i) factors[j].pb(i);
    rep2(i,2,maxn) reverse(all(factors[i]));
    rep2(i,2,maxk+1){
        cnt[i][i]=0;
        rep2(j,i+1,maxn){
            cnt[i][j]=cnt[i][j-1];
            for(auto x: factors[j]){
                if(x>=i) cnt[i][j]+=phi[j/x];
                else break;
            }
        }
    }
    rep2(i,1,maxm-1){
        bug(i);
        segment_tree tree(maxn/2,1);
        rep2(j,1,maxn-2) dp[i+1][j]=inf;
        rep2(j,1,maxk) rep2(k,j+1,maxn-2) chkmin(dp[i+1][k],dp[i][j]+cnt[j+1][k]);
        rep2(j,1,maxk) tree.modify(1,1,maxn/2-1,j,j,inf);
        rep2(j,maxk,maxn/2) tree.modify(1,1,maxn/2-1,j,j,dp[i][j]);
        rep2(j,maxk,maxn-2){
            for(auto x: factors[j]){
                if(x>=maxk) tree.modify(1,1,maxn/2-1,1,x-1,phi[j/x]);
                else break;
            }
            chkmin(dp[i+1][j],tree.query(1,1,maxn/2-1,1,j-1));
        }
    }
    int tt;
    cin >> tt;
    while(tt--){
        int n,k;
        cin >> n >> k;
        if(k>=maxm) print(n);
        else print(n+dp[k][n]);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    freopen("output2.txt","w",stderr);
    #endif
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    while(t--) orzck();
    return 0;
}