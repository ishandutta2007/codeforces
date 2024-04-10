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
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=100005;
//i_am_noob
int t,n,arr[maxn],ans[maxn];
string str;
vector<int> vec,vec1[3],vec2;

void query(vector<int> &vec){
    if(vec.empty()) return;
    print0("Q"),print0(sz(vec)>>1);
    for(auto i: vec) print0(i+1);
    cout << endl;
    cin >> str;
    rep(sz(vec)>>1) arr[vec[2*i+1]]=str[i]-'0';
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();
        rep(n>>1) vec.pb(2*i),vec.pb(2*i+1);
        query(vec);
        vec.clear();
        rep(n-1>>1) vec.pb(2*i+1),vec.pb(2*i+2);
        query(vec);
        vec2.clear();
        rep(n) if(i==0||arr[i]==0) vec2.pb(i);
        if(sz(vec2)==1){
            print4("A",n,0,0);
            cout << flush;
            rep(n) print0(i+1);
            rep(3) cout << endl;
            continue;
        }
        vec.clear();
        rep(n){
            if(4*i+2>=sz(vec2)) break;
            vec.pb(vec2[4*i]),vec.pb(vec2[4*i+2]);
            if(4*i+3>=sz(vec2)) break;
            vec.pb(vec2[4*i+1]),vec.pb(vec2[4*i+3]);
        }
        query(vec);
        vec.clear();
        rep(n){
            if(4*i+4>=sz(vec2)) break;
            vec.pb(vec2[4*i+2]),vec.pb(vec2[4*i+4]);
            if(4*i+5>=sz(vec2)) break;
            vec.pb(vec2[4*i+3]),vec.pb(vec2[4*i+5]);
        }
        query(vec);
        rep(n) ans[i]=-1;
        ans[vec2[0]]=0,ans[vec2[1]]=1;
        rep2(i,2,sz(vec2)) ans[vec2[i]]=(arr[vec2[i]]?ans[vec2[i-2]]:3-ans[vec2[i-2]]-ans[vec2[i-1]]);
        rep(n) if(ans[i]==-1) ans[i]=ans[i-1];
        rep(3) vec1[i].clear();
        rep(n) vec1[ans[i]].pb(i);
        print4("A",sz(vec1[0]),sz(vec1[1]),sz(vec1[2]));
        cout << flush;
        rep(3){
            for(auto j: vec1[i]) print0(j+1);
            cout << endl;
        }
    }
    return 0;
}