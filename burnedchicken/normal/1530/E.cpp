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
const int maxn=200005;

//i_am_noob
#define wiwihorz  
int n,cnt[26];
string str;

void orzck(){
    cin >> str;
    n=sz(str);
    rep(26) cnt[i]=0;
    rep(n) cnt[str[i]-'a']++;
    bool flag=0;
    rep(26) if(cnt[i]==1) flag=1;
    if(flag){
        int k;
        rep(26) if(cnt[i]==1){
            k=i;
            break;
        }
        cout << char('a'+k);
        rep(26){
            if(i==k) rep1(j,cnt[i]-1) cout << char('a'+i);
            else rep1(j,cnt[i]) cout << char('a'+i);
        }
        cout << "\n";
        return;
    }
    int c0=-1,c1=-1;
    rep(26) if(cnt[i]){
        if(c0==-1) c0=i;
        else{
            c1=i;
            break;
        }
    }
    if(cnt[c0]==n){
        print(str);
        return;
    }
    if(cnt[c0]-1<=ceiling(n-1,2)){
        bug(str);
        cout << char('a'+c0);
        cnt[c0]--;
        bool flag=1;
        rep1(_,n-1){
            rep(26) if(cnt[i]){
                if(i==c0&&!flag) continue;
                cout << char('a'+i);
                cnt[i]--;
                break;
            }
            flag^=1;
        }
        cout << "\n";
        return;
    }
    if(cnt[c0]+cnt[c1]!=n){
        bug(str);
        cout << char('a'+c0);
        cout << char('a'+c1);
        cnt[c0]--,cnt[c1]--;
        rep(cnt[c0]) cout << char('a'+c0);
        cnt[c0]=0;
        rep(26) if(cnt[i]&&i!=c0&&i!=c1){
            cout << char('a'+i);
            cnt[i]--;
            break;
        }
        rep(26) rep1(j,cnt[i]) cout << char('a'+i);
        cout << "\n";
        return;
    }
    bug(str);
    cout << char('a'+c0);
    rep(cnt[c1]) cout << char('a'+c1);
    rep(cnt[c0]-1) cout << char('a'+c0);
    cout << "\n";
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