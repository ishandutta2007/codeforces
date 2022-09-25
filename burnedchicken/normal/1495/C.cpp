#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")

#define ll long long
#define int ll
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
const int maxn=100005;
//i_am_noob
#define wiwihorz  
int n,m;
char c[505][505];
bool flag;

void hhhhauraorz(){
    cin >> n >> m;
    rep(n) rep1(j,m) cin >> c[i][j];
    if(n%3==0){
        rep(n) rep1(j,m) if(i%3==1) c[i][j]='X';
        rep(n-1) if(i%3==2){
            flag=false;
            rep1(j,m){
                if(c[i][j]=='X'){
                    c[i+1][j]='X';
                    flag=true;
                    break;
                }
                if(c[i+1][j]=='X'){
                    c[i][j]='X';
                    flag=true;
                    break;
                }
            }
            if(!flag) c[i][0]=c[i+1][0]='X';
        }
    }
    else{
        rep(n) rep1(j,m) if(i%3==0) c[i][j]='X';
        rep(n-1) if(i%3==1){
            flag=false;
            rep1(j,m){
                if(c[i][j]=='X'){
                    c[i+1][j]='X';
                    flag=true;
                    break;
                }
                if(c[i+1][j]=='X'){
                    c[i][j]='X';
                    flag=true;
                    break;
                }
            }
            if(!flag) c[i][0]=c[i+1][0]='X';
        }
    }
    rep(n){
        rep1(j,m) cout << c[i][j];
        cout << "\n";
    }
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