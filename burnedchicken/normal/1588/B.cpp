#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")

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
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=300005,maxm=7777714,maxk=7777714;
    
//i_am_noob
#define wiwihorz  
int n;

int query(int l, int r){
    print("?",l,r);
    cout << flush;
    int res;
    cin >> res;
    return res;
}

void orzck(){
    cin >> n;
    int l=1,r=n;
    int tot=query(1,n);
    while(l<r){
        int mid=l+r+1>>1;
        int x=query(1,mid-1),y;
        if(x==tot){
            r=mid-1;
            continue;
        }
        if(x==0){
            l=mid;
            continue;
        }
        y=query(mid,n);
        int xx=x-query(1,mid-2);
        int res1,res2,res3;
        bug(x,xx);
        if(xx*(xx+1)/2==x){
            res1=mid-1-xx;
            res2=mid+(tot-x-y)/(xx+1);
            res3=res2+query(res2,n)-query(res2+1,n);
            print("!",res1,res2,res3);
            cout << flush;
            break;
        }
        int yy=y-query(mid+1,n);
        if(yy*(yy+1)/2==y){
            res3=mid+yy;
            res2=mid-(tot-x-y)/(yy+1);
            res1=res2-1-(query(1,res2-1)-query(1,res2-2));
            print("!",res1,res2,res3);
            cout << flush;
            break;
        }
        assert(0);
    }
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