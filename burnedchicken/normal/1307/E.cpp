#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
const int maxn=5005;
//i_am_noob
int n,m,s[maxn],f[maxn],h[maxn],posl[maxn],posr[maxn],cnt,x,y,z;
vector<int> vec[maxn],vec2[maxn];
bool flag;
set<int> st;

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

Modint<MOD> ans[maxn],cur;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(n) cin >> s[i];
    rep(m) cin >> f[i] >> h[i];
    rep(n) s[i]--;
    rep(m) f[i]--;
    rep(n) vec[s[i]].pb(i);
    rep(m) vec2[f[i]].pb(i);
    rep(m){
        if(h[i]>sz(vec[f[i]])) posl[i]=n,posr[i]=-1;
        else posl[i]=vec[f[i]][h[i]-1],posr[i]=vec[f[i]][sz(vec[f[i]])-h[i]];
        //print3(i,posl[i],posr[i]);
    }
    ans[0]=1;
    rep(n+1){
        flag=false;
        if(i>0) rep1(j,m) if(posl[j]==i-1) flag=true;
        if(i&&!flag) continue;
        cnt=i!=0;
        cur=1;
        rep1(j,n){
            x=y=z=0;
            if(i&&j==s[i-1]){
                for(auto k: vec2[j]) if(posl[k]!=i-1&&posr[k]>=i) y++;
                if(y){
                    cnt++;
                    cur*=y;
                }
                continue;
            }
            for(auto k: vec2[j]){
                if(posl[k]<i&&posr[k]>=i) z++;
                else if(posl[k]<i) x++;
                else if(posr[k]>=i) y++;
            }
            if(x==0&&y==0&&z==0);
            else if((y==0&&z==0)||(x==0&&z==0)||(x==0&&y==0&&z==1)){
                cnt+=1;
                cur*=x+y+2*z;
            }
            else{
                cnt+=2;
                cur*=(x*(y+z)+z*(y+z-1+MOD))%MOD;
            }
        }
        //print3(i,cnt,cur);
        if(cnt) ans[cnt]+=cur;
        st.insert(cnt);
    }
    st.insert(0);
    rep3(i,m,0) if(st.count(i)){
        print2(i,ans[i]);
        return 0;
    }
    return 0;
}