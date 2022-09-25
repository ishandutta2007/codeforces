#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
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
#define inf 1010000000
//#define inf 4000000000000000000
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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

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
template<typename T, signed N>
struct BIT{
    T val[N];
    void modify(signed x, T y){for(signed i=++x; i<N; i+=i&-i) val[i]+=y;}
    T query(signed x, signed y){
        T ret=0;
        for(signed i=++y; i; i-=i&-i) ret+=val[i];
        for(signed i=x; i; i-=i&-i) ret-=val[i];
        return ret;
    }
    signed first_true(bool(*f)(T,signed)){
        if(f(0,0)) return 0;
        signed cur=0;
        T curval=0;
        for(signed i=__lg(N); i>=0; --i) if(cur+(1<<i)<N){
            if(!f(curval+val[cur+(1<<i)],cur+(1<<i))) cur+=1<<i,curval+=val[cur];
        }
        return min(cur,N-2);
    }
};
const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=1000005;

//i_am_noob
//#define wiwihorz  
int n,a[maxn],curval[maxn];
ll res;
string str;
NT<maxn> nt;
vector<pii> vec[maxn];
vector<pii> op[maxn];
BIT<signed,maxn> bit;

void orzck(){
    cin >> n;
    rep(n) cin >> a[i];
    cin >> str;
    rep(n){
        int x=a[i];
        int sign=1;
        if(str[i]=='/') sign=-1;
        while(x>1){
            int p=nt.lpd[x];
            bug(i,p);
            if(sz(vec[p])&&vec[p].back().second==i) vec[p].back().first+=sign,bug(sign);
            else vec[p].pb({sign,i});
            x/=p;
        }
    }
    rep(maxn) curval[i]=-1;
    rep(maxn) if(sz(vec[i])){
        rep2(j,1,sz(vec[i])) vec[i][j].first+=vec[i][j-1].first;
        vector<pii> stk;
        rep3(j,sz(vec[i])-1,0){
            while(sz(stk)&&vec[i][j].first<=stk.back().first) stk.pop_back();
            op[vec[i][j].second].pb({sz(stk)?stk.back().second:n,i});
            stk.pb(vec[i][j]);
            bug(i,vec[i][j].first,vec[i][j].second);
        }
        while(sz(stk)&&stk.back().first>=0) stk.pop_back();
        curval[i]=sz(stk)?stk.back().second:n;
    }
    rep(maxn) if(curval[i]!=-1) bit.modify(curval[i],1);
    bit.modify(n,1);
    rep(n){
        res+=bit.first_true([](int x, int y){return x>0;})-i;
        for(auto [x,y]: op[i]){
            bit.modify(curval[y],-1);
            curval[y]=x;
            bit.modify(x,1);
        }
    }
    print(res);
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