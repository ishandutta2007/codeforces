#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define ll long long
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
const int maxn=100000005;
//i_am_noob
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,x;
    ll y;
    unsigned a[4],ans=0,k,l;
    bool flag,flag2;
    bitset<maxn> bs;
    bs.set();
    bs[0]=0;
    rep2(i,1,maxn){
        x=6*(i>>1)+4*(i&1)+1;
        if(bs[i]){
            if(1ll*x*x<3*maxn) for(int j=x*x; j<3*maxn; j+=2*x) if(j%3) bs[j/3]=0;
        }
    }
    cin >> n;
    rep(4) cin >> a[i];
    rep2(i,-1,maxn){
        if(i==-1) x=2;
        else if(i==0) x=3;
        else x=6*(i>>1)+4*(i&1)+1;
        if(i>0&&bs[i]==0) continue;
        k=0,y=x;
        while(1){
            if(y>n) break;
            k+=n/y;
            y*=x;
        }
        l=a[0]*x*x*x+a[1]*x*x+a[2]*x+a[3];
        ans+=k*l;
    }
    print1(ans);
    return 0;
}