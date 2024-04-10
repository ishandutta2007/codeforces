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
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=1005;
//i_am_noob
int n,ans[maxn]={0},mask[maxn],rev[1024],total=0,x=0,lca[70],k[3];
vector<int> vec;

int query(vector<int> vec){
    if(vec.empty()) return 0;
    print0("?"),print0(sz(vec));
    for(auto i: vec) print0(i+1);
    cout << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(70) lca[i]=pow2(10)-1;
    rep(n){
        while(__builtin_popcountll(x)<1||__builtin_popcountll(x)>8) x++;
        mask[i]=x;
        x++;
    }
    rep(pow2(10)) rev[i]=-1;
    rep(n) rev[mask[i]]=i;
    rep(10){
        vec.clear();
        rep1(j,n) if((mask[j]&pow2(i))==0) vec.pb(j);
        x=query(vec);
        total|=x;
        rep1(j,63) if(x&pow2(j)) lca[j]&=pow2(10)-1-pow2(i);
    }
    rep(3){
        vec.clear();
        rep1(j,n) if((__builtin_popcountll(mask[j])-1)&pow2(i)) vec.pb(j);
        k[i]=query(vec);
    }
    rep(63){
        if(__builtin_popcountll(lca[i])>8) continue;
        if(__builtin_popcountll(lca[i])==0) rep1(j,n) ans[j]|=pow2(i);
        else{
            x=0;
            rep1(j,3) if(((__builtin_popcountll(lca[i])-1)&pow2(j))==0) x|=k[j];
            if(x&pow2(i)) rep1(j,n) ans[j]|=pow2(i);
            else rep1(j,n) if(j!=rev[lca[i]]) ans[j]|=pow2(i);
        }
    }
    print0("!");
    rep(n) print0(ans[i]);
    cout << endl;
    return 0;
}