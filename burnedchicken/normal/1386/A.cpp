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
const int MOD=Mod2;
const int maxn=205;
//i_am_noob
int t,n,l,r,mid,x,y,lst,c;
vector<int> vec;

void query(int k){
    print2("?",k);
    cout << flush;
    int tmp;
    #ifdef i_am_noob
    if(lst==-1) tmp=1;
    else tmp=abs(k-lst)>=c?1:0;
    #else
    cin >> tmp;
    #endif
    if(lst!=-1){
        if(tmp==1) r=abs(k-lst);
        else l=abs(k-lst)+1;
    }
    lst=k;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        #ifdef i_am_noob
        cin >> c;
        #endif
        vec.clear();
        l=1,r=n;
        rep2(i,1,64){
            vec.pb(ceiling(n,pow2(i))>>1);
            if(vec.back()==0){
                vec.pop_back();
                break;
            }
        }
        x=1,y=n,lst=-1;
        rep(sz(vec)) i&1?y-=vec[i]:x+=vec[i];
        reverse(all(vec));
        query(x);
        query(y);
        while(l<r){
            if(l>y-x) query(x-=vec.back());
            else query(x+=vec.back());
            vec.pop_back();
            if(l==r) break;
            if(l>y-x) query(y+=vec.back());
            else query(y-=vec.back());
            vec.pop_back();
        }
        print2("=",l);
        cout << flush;
        #ifdef i_am_noob
        print1(l==c?"AC":"WA");
        #endif
    }
    return 0;
}