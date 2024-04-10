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
const int maxn=10005;
//i_am_noob
int n,x,y,k1,k2,a[maxn];
set<int> st1,st2;

int query(int x, int y){
    print3("?",x+1,y+1);
    cout << flush;
    int tmp;
    cin >> tmp;
    return tmp;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    //PixelCatorz
    cin >> n;
    rep(n) st1.insert(i),st2.insert(i+1);
    rep(n){
        if(sz(st1)==1){
            a[*st1.begin()]=*st2.begin();
            break;
        }
        x=*st1.begin(),y=*++st1.begin();
        k1=query(x,y),k2=query(y,x);
        if(k1>k2){
            a[x]=k1;
            st1.erase(x),st2.erase(k1);
        }
        else{
            a[y]=k2;
            st1.erase(y),st2.erase(k2);
        }
    }
    print0("!");
    rep(n) print0(a[i]);
    cout << endl;
    return 0;
}