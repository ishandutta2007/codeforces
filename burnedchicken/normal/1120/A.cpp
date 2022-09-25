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

const int maxn=500005;
//i_am_noob
int m,k,n,s,a[maxn],x;
vector<int> vec;
map<int,int> ma,total,sum[maxn],sum2[maxn];
bool flag;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> m >> k >> n >> s;
    rep(m) cin >> a[i];
    rep(s){
        cin >> x;
        ma[x]++;
    }
    rep(m) if(ma.count(a[i])) total[a[i]]++;
    rep2(i,1,n){
        sum[i]=sum[i-1];
        rep1(j,k) if(ma.count(a[(i-1)*k+j])) sum[i][a[(i-1)*k+j]]++;
    }
    rep2(i,1,n){
        sum2[i]=sum2[i-1];
        rep1(j,k) if(ma.count(a[m-1-((i-1)*k+j)])) sum2[i][a[m-1-((i-1)*k+j)]]++;
    }
    rep(n){
        flag=true;
        for(auto p: ma) if(p.second+sum[i][p.first]+sum2[n-1-i][p.first]>total[p.first]) flag=false;
        if(flag){
            rep2(j,i*k,(i+1)*k+m-n*k){
                if(!ma.count(a[j])) vec.pb(j+1);
                else if(ma[a[j]]==0) vec.pb(j+1);
                else ma[a[j]]--;
            }
            print1(min(m-n*k,sz(vec)));
            rep1(j,min(m-n*k,sz(vec))) print0(vec[j]);
            cout << "\n";
            return 0;
        }
    }
    print1(-1);
    return 0;
}