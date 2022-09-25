#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

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
#define bug(...) 826
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;
const int maxn=605;

//i_am_noob
//#define wiwihorz  
int n,par[maxn];
vector<int> v[2];
set<int> st;

int query(vector<int> vec){
    print("?",sz(vec));
    for(auto i: vec) print0(i+1);
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int query(vector<int> vec1, vector<int> vec2){
    print("?",sz(vec1)+sz(vec2));
    for(auto i: vec1) print0(i+1);
    for(auto i: vec2) print0(i+1);
    cout << endl;
    int res;
    cin >> res;
    return res;
}

int find_edge(vector<int> vec, int x){
    int l=0,r=sz(vec)-1;
    while(l<r){
        int mid=l+r>>1;
        vector<int> tmp;
        rep(mid+1) tmp.pb(vec[i]);
        if(query(tmp,{x})) r=mid;
        else l=mid+1;
    }
    return vec[l];
}

void orzck(){
    cin >> n;
    rep2(i,1,n) st.insert(i);
    v[0].pb(0);
    while(sz(st)){
        vector<int> vec;
        for(auto i: st) vec.pb(i);
        int cnt0=query(v[0],vec),cnt1=query(v[1],vec);
        int k;
        if(cnt0>cnt1) k=0;
        else k=1;
        int l=0,r=sz(vec)-1;
        while(l<r){
            int mid=l+r>>1;
            vector<int> tmp;
            rep(mid+1) tmp.pb(vec[i]);
            if(query(v[k],tmp)==query(tmp)) l=mid+1;
            else r=mid;
        }
        vector<int> tmp;
        int u=vec[l];
        tmp.pb(u);
        par[u]=find_edge(v[k],u);
        if(query(v[k^1],tmp)){
            int x=find_edge(v[k^1],u);
            vector<int> res1,res2;
            set<int> vis;
            for(int i=u; i!=0; i=par[i]) res1.pb(i);
            res1.pb(0);
            for(auto i: res1) vis.insert(i);
            for(int i=x; i!=0; i=par[i]) res2.pb(i);
            res2.pb(0);
            int lca;
            for(auto i: res2) if(vis.count(i)){
                lca=i;
                break;
            }
            while(res2.back()!=lca) res2.pop_back();
            res2.pop_back();
            reverse(all(res2));
            vector<int> res;
            for(auto i: res1){
                res.pb(i);
                if(i==lca) break;
            }
            for(auto i: res2) res.pb(i);
            print("N",sz(res));
            for(auto i: res) print0(i+1);
            cout << "\n";
            return;
        }
        bug(k^1,u);
        v[k^1].pb(u);
        st.erase(u);
    }
    print("Y",sz(v[0]));
    for(auto i: v[0]) print0(i+1);
    cout << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    //freopen("input1.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    //freopen("output2.txt","w",stderr);
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