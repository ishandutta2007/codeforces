#include <bits/stdc++.h>
#include <bits/extc++.h>

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
#define mp make_pair
//#define inf 2000000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005;
//i_am_noob
ykh;

template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(val*o.val%mod);}
    Modint operator +=(const Modint& o){*this=(*this)+o;return *this;}
    Modint operator -=(const Modint& o){*this=(*this)-o;return *this;}
    Modint operator *=(const Modint& o){*this=(*this)*o;return *this;}
    Modint Pow(int b) const {
        Modint tmp(val),ret(1);
        while(b){
            if(b&1) ret*=tmp;
            b>>=1;tmp*=tmp;
        }
        return ret;
    }
    Modint Pow(const Modint& a, int b) const {return a.Pow(b);}
    inline Modint inv() const {return (*this).Pow(mod-2);}
    Modint operator /(const Modint& o) const {return *this*o.inv();}
    bool operator ==(const Modint& o) const {return val==o.val;}
};
#define modint Modint<MOD>

bool operator <(const vector<int>& vec1, const vector<int>& vec2){
    rep(sz(vec1)){
        if(vec1[i]<vec2[i]) return true;
        if(vec1[i]>vec2[i]) return false;
    }
    return false;
}

int t,n,a[maxn],ans;
modint hs[maxn][5],powseed[maxn],cur[5];
vector<int> vec,vec1;
map<vector<int>,int> cnt;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(maxn) rep1(j,5) while(!hs[i][j]) hs[i][j]=rng()%MOD;
    powseed[0]=1;
    while(!powseed[1]) powseed[1]=rng()%MOD;
    rep2(i,2,maxn) powseed[i]=powseed[i-1]*powseed[1];
    cin >> t;
    while(t--){
        cin >> n;
        rep(n) cin >> a[i];
        vec.clear();
        cnt.clear();
        ans=0;
        rep(5) cur[i]=0;
        vec1.clear();
        rep(5) vec1.pb(cur[i]);
        cnt[vec1]++;
        rep(n){
            if(sz(vec)&&vec.back()==a[i]){
                rep1(j,5) cur[j]-=hs[a[i]][j]*powseed[sz(vec)-1];
                vec.pop_back();
            }
            else{
                rep1(j,5) cur[j]+=hs[a[i]][j]*powseed[sz(vec)];
                vec.pb(a[i]);
            }
            vec1.clear();
            rep(5) vec1.pb(cur[i]);
            ans+=cnt[vec1];
            cnt[vec1]++;
        }
        print1(ans);
    }
    return 0;
}