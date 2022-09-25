#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
#define pii pair<signed,signed>
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

const int maxn=100005;

//i_am_noob
//#define wiwihorz  
vector<signed> kmp(string str){
    vector<signed> res;
    res.pb(-1);
    rep2(i,1,sz(str)){
        signed cur=res[i-1];
        while(1){
            if(str[cur+1]==str[i]){
                res.pb(cur+1);
                break;
            }
            if(cur<0) break;
            cur=res[cur];
        }
        if(sz(res)<i+1) res.pb(-1);
    }
    return res;
}

signed match(string str1, string str2){
    vector<signed> vec=kmp(str1);
    signed cur=-1,res=0;
    for(auto c: str2){
        while(str1[cur+1]!=c){
            if(cur==-1) break;
            cur=vec[cur];
        }
        if(str1[cur+1]==c) cur++;
        if(cur+1==sz(str1)) res++,cur=vec[cur];
    }
    return res;
}

const int mod=998244853;

int add(int x, int y){x+=y;return x>=mod?x-mod:x;}
pii operator +(const pii& p1, const pii& p2){return {add(p1.first,p2.first),add(p1.second,p2.second)};}
pii operator *(const pii& p1, const pii& p2){return {1ll*p1.first*p2.first%mod,1ll*p1.second*p2.second%mod};}
pii operator +=(pii& p1, const pii& p2){p1.first=add(p1.first,p2.first),p1.second=add(p1.second,p2.second);return p1;}
pii operator *=(pii& p1, const pii& p2){p1.first=1ll*p1.first*p2.first%mod,p1.second=1ll*p1.second*p2.second%mod;return p1;}

template<int maxn>
struct rhash{
    pii seed[maxn];
    void init(int seed1, int seed2){
        seed1%=mod,seed2%=mod;
        seed[0]={1,1};
        seed[1]={seed1,seed2};
        rep2(i,2,maxn) seed[i]=seed[i-1]*seed[1];
    }
    pii val(string str, int base){
        pii res={0,0};
        rep(sz(str)) res+=pii(str[i],str[i])*seed[i+1];
        res*=seed[base];
        return res;
    }
    pii val(char ch, int base){return pii(ch,ch)*seed[base+1];}
};
rhash<maxn> hs;

const int de=20;

int n,q;
string str;
set<int> st;
pii p[maxn][de],old[maxn][de];
vector<pii> vec;
vector<vector<signed>> vals;

void upd(){
    st.clear();
    rep(sz(vals)) vals[i].clear();
    rep(n) rep1(j,de) if(i+j<n){
        old[i][j]=p[i][j];
        auto it=lower_bound(all(vec),p[i][j]);
        if(it==vec.end()) continue;
        if(p[i][j]!=*it) continue;
        vals[it-vec.begin()].pb(i);
    }
}

bool vis[maxn];

int solve(int l, int r, string str2){
    int m=sz(str2);
    if(r-l+1<m) return 0;
    if(m>de) return match(str2,str.substr(l,r-l+1));
    pii hsval=hs.val(str2,0);
    assert(binary_search(all(vec),hsval));
    int id=lower_bound(all(vec),hsval)-vec.begin();
    int res=upper_bound(all(vals[id]),r-(m-1))-lower_bound(all(vals[id]),l);
    int cur=-1;
    for(auto i: st){
        rep2(j,max(i-m+1,l),min(i,r-(m-1))+1) if(cur<j&&j+m-1<n){
            if(old[j][m-1]==hsval) res--;
            if(p[j][m-1]==hsval) res++;
            cur=j;
        }
    }
    if(sz(st)>4000) upd();
    return res;
}

int brute(int l, int r, string str2){
    int res=0;
    rep2(i,l,r+1-(sz(str2)-1)) if(str2==str.substr(i,sz(str2))) res++;
    return res;
}

struct query{
    int op,x,l,r;
    char c;
    string str2;
}qu[maxn];

ykh;

void orzck(){
    cin >> str >> q;
    n=sz(str);
    hs.init(rng()%mod,rng()%mod);
    rep(n) rep1(j,de) if(i+j<n){
        if(j==0) p[i][j]=hs.val(str[i+j],j);
        else p[i][j]=p[i][j-1]+hs.val(str[i+j],j);
    }
    rep(q){
        cin >> qu[i].op;
        if(qu[i].op==1){
            cin >> qu[i].x >> qu[i].c;
            qu[i].x--;
        }
        else{
            cin >> qu[i].l >> qu[i].r >> qu[i].str2;
            qu[i].l--,qu[i].r--;
            vec.pb(hs.val(qu[i].str2,0));
        }
    }
    sort(all(vec));
    vec.resize(unique(all(vec))-vec.begin());
    bug(sz(vec));
    vals.resize(sz(vec));
    upd();
    rep1(t,q){
        if(qu[t].op==1){
            str[qu[t].x]=qu[t].c;
            rep2(i,max(qu[t].x-de+1,0ll),qu[t].x+1){
                pii nw={0,0};
                rep1(j,de) if(i+j<sz(str)){
                    nw=nw+hs.val(str[i+j],j);
                    p[i][j]=nw;
                }
            }
            st.insert(qu[t].x);
        }
        else{
            print(solve(qu[t].l,qu[t].r,qu[t].str2));
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}