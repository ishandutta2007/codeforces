#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,tune=native")

#define int long long
#define ull unsigned long long
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
const int MOD=Mod2;
const int maxn=400005;
//i_am_noob
int n,q,lst,op,l,r,x,cur;
unordered_map<int,int> mm;

int par[maxn],siz[maxn],val[maxn];
vector<int> have[maxn];

int Find(int x){return x==par[x]?x:par[x]=Find(par[x]);}
void Union(int x, int y, int k){
    k^=val[x]^val[y];
    x=Find(x),y=Find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    par[y]=x;
    siz[x]+=siz[y];
    for(auto i: have[y]){
        have[x].pb(i);
        val[i]^=k;
    }
    have[y].clear();
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(maxn) par[i]=i,siz[i]=1,have[i].pb(i);
    cin >> q;
    while(q--){
        cin >> op >> l >> r;
        l^=lst,r^=lst;
        if(l>r) swap(l,r);
        r++;
        if(mm.find(l)==mm.end()) mm[l]=cur++;
        if(mm.find(r)==mm.end()) mm[r]=cur++;
        l=mm[l],r=mm[r];
        if(op==1){
            cin >> x;
            x^=lst;
            Union(l,r,x);
        }
        else{
            if(Find(l)!=Find(r)){
                print(-1);
                lst=1;
            }
            else{
                print(val[l]^val[r]);
                lst=val[l]^val[r];
            }
        }
    }
    return 0;
}