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
const int MOD=Mod;
 
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
ykh;
int n,a[maxn],noob,cur,rnd[maxn],x,y=0;
bool vis[maxn];
 
void solve(){
    noob=4000000/n;
    while(noob--){
        cur=-1;
        shuffle(rnd,rnd+n,rng);
        memset(vis,0,n);
        rep(n){
            if(cur==-1){
                cur=a[rnd[i]],vis[rnd[i]]=true;
                if(cur==1) break;
                continue;
            }
            x=__gcd(cur,a[rnd[i]]);
            if(x<cur) cur=x,vis[rnd[i]]=true;
        }
        if(cur!=1) continue;
        cur=-1;
        rep(n) if(!vis[i]) cur=(cur==-1?a[i]:__gcd(cur,a[i]));
        if(cur!=1) continue;
        print1("YES");
        //print1(4000000/n-noob);
        rep(n) print0(1+vis[i]);
        cout << "\n";
        return;
    }
    print1("NO");
}
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    //freopen("a.txt","r",stdin);
    cin >> n;
    rep(n) cin >> a[i];
    rep(n) rnd[i]=i;
    solve();
    return 0;
}