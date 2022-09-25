#include <bits/stdc++.h>
#include <bits/extc++.h>

//#define int long long
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
#define inf 8000000000000000000
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
const int maxn=3005;
//i_am_noob
int n,x,y;
string str;
vector<string> vec={"0011","0101","1110","1111"};
bool flag,b[maxn];
ykh;

template <int mod>
struct Modint{
    int val;
    Modint(int _val=0){val=_val;}
    operator int() const {return (*this).val;}
    Modint operator +(const Modint& o) const {return val+o.val>=mod?Modint(val+o.val-mod):Modint(val+o.val);}
    Modint operator -() const {return val?Modint(mod-val):*this;}
    Modint operator -(const Modint& o) const {return val-o.val<0?Modint(val-o.val+mod):Modint(val-o.val);}
    Modint operator *(const Modint& o) const {return Modint(1ll*val*o.val%mod);}
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
modint dp[maxn][maxn],ans;
vector<int> f[maxn];

void kmp(string &str, vector<int> &fail){
    fail.pb(0);
    int cur=0;
    rep2(i,1,sz(str)){
        while(cur&&str[i]!=str[cur]) cur=fail[cur-1];
        if(str[i]==str[cur]) cur++;
        fail.pb(cur);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n){
        cin >> x;
        str.pb(x?'1':'0');
    }
    rep(n-3) if(!binary_search(all(vec),str.substr(i,4))) b[i]=true;
    rep(n){
        kmp(str,f[i]);
        str.erase(str.begin());
    }
    rep(n){
        y=0;
        rep1(j,i) y=max(y,f[j][i-j]);
        rep3(j,i,0){
            if(i-j<=2||(i-j==3&&b[j])) dp[j][i]=1;
            rep2(k,1,min(5,i-j+1)) if(k<=3||b[i-k+1]) dp[j][i]+=dp[j][i-k];
            if(i-j+1>y) ans+=dp[j][i];
        }
        print1(ans);
    }
    return 0;
}