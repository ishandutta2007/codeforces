#include <bits/stdc++.h>
using namespace std;

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
const int MOD=Mod;
const int maxn=1000005;
//i_am_noob
int n,k,a[maxn],maxx=-inf,minn=inf,maxid,minid,x;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    #ifdef i_am_noob
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin >> n >> k;
    rep(150){
        print("?",1);
        cout << flush;
        cin >> x;
    }
    if(n<=500){
        for(int i=0; i<n; i++){
            print("?",i+1);
            cout << flush;
            cin >> a[i];
            if(a[i]>k) if(a[i]>maxx) maxx=a[i],maxid=i;
            if(a[i]<k) if(a[i]<minn) minn=a[i],minid=i;
        }
    }
    else for(int i=0; i<n; i+=290){
        print("?",i+1);
        cout << flush;
        cin >> a[i];
        if(a[i]>k) if(a[i]>maxx) maxx=a[i],maxid=i;
        if(a[i]<k) if(a[i]<minn) minn=a[i],minid=i;
    }
    if(maxx!=-inf){
        while(1){
            maxid=(maxid-1+n)%n;
            print("?",maxid+1);
            cout << flush;
            cin >> x;
            if(x==k){
                print("!",maxid+1);
                cout << flush;
                return 0;
            }
        }
    }
    if(minn!=inf){
        while(1){
            minid=(minid+1)%n;
            print("?",minid+1);
            cout << flush;
            cin >> x;
            if(x==k){
                print("!",minid+1);
                cout << flush;
                return 0;
            }
        }
    }
    return 0;
}