#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
//#define int ll
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
const int maxn=300005;
//i_am_noob
//#define wiwihorz  
const int maxm=2500005;
int n,a[maxn],id[maxn],cnt[maxm];
vector<pii> vec[2*maxm];

void hhhhauraorz(){
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) id[i]=i;
    sort(id,id+n,[](int i, int j){return a[i]<a[j];});
    if(n>=3500){
        rep(n-1) cnt[a[id[i+1]]-a[id[i]]]++;
        int x=max_element(cnt,cnt+maxm)-cnt;
        vector<pii> res;
        rep(n-1) if(a[id[i+1]]-a[id[i]]==x) res.pb({id[i],id[i+1]});
        print("YES");
        print(res[0].first+1,res.back().second+1,res[0].second+1,res.back().first+1);
        return;
    }
    rep(n) rep2(j,i+1,n){
        if(a[i]<=a[j]) vec[a[i]+a[j]].pb({i,j});
        else vec[a[i]+a[j]].pb({j,i});
    }
    rep(n) cnt[a[i]]++;
    rep(2*maxm) if(sz(vec[i])>=2){
        rep2(j,1,sz(vec[i])) if(a[vec[i][j].first]!=a[vec[i][0].first]){
            print("YES");
            print(vec[i][0].first+1,vec[i][0].second+1,vec[i][j].first+1,vec[i][j].second+1);
            return;
        }
        if((i==2*a[vec[i][0].first]&&cnt[a[vec[i][0].first]]>=4)||(i!=2*a[vec[i][0].first]&&cnt[a[vec[i][0].first]]>=2&&cnt[a[vec[i][0].second]]>=2)){
            print("YES");
            set<int> st,st2;
            rep1(j,n) if(a[vec[i][0].first]==a[j]){
                st.insert(j);
                if(sz(st)==2) break;
            }
            rep1(j,n) if(a[vec[i][0].second]==a[j]&&!st.count(j)){
                st2.insert(j);
                if(sz(st2)==2) break;
            }
            print((*st.begin())+1,(*st2.begin())+1,(*st.rbegin())+1,(*st2.rbegin())+1);
            return;
        }
    }
    print("NO");
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