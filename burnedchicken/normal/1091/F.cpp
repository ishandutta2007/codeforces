#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
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
const int maxn=100005;
//i_am_noob
int n,a[maxn],cur,minn,minid,havew,haveg,ans;
string str;
bool flag;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n;
    rep(n) cin >> a[i];
    cin >> str;
    rep(n){
        if(str[i]=='L') ans+=a[i];
        else if(str[i]=='W') ans+=a[i]*3;
        else ans+=a[i]*5;
    }
    rep(n){
        if(str[i]=='L') cur-=a[i];
        else cur+=a[i];
        if(cur<minn) minn=cur,minid=i+1;
    }
    cur=0;
    bug(minid);
    rep(minid){
        if(str[i]=='L') cur-=a[i];
        else cur+=a[i];
        if(str[i]=='W') flag=true;
        if(cur<0){
            if(flag) ans+=3*-cur;
            else ans+=5*-cur;
            cur=0;
        }
    }
    cur=0;
    rep3(i,n-1,minid){
        if(str[i]=='L') cur+=2*a[i];
        else if(str[i]=='W') cur-=2*a[i],havew+=2*a[i];
        else cur-=2*a[i],haveg+=2*a[i];
        if(cur<0){
            int tmp=min(-cur/2,haveg);
            ans-=tmp*2;
            cur+=2*tmp,haveg-=tmp;
        }
        if(cur<0){
            int tmp=min(-cur/2,havew);
            ans-=tmp;
            cur+=2*tmp,havew-=tmp;
        }
    }
    print(ans);
    return 0;
}