#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int maxn=200005;
//i_am_noob
int n,cur,x,cur2,cur3;
vector<int> vec,ans1,ans3;
vector<char> ans2;
set<int> st;

void op1(int x, int y){
    //print3(x,y,'+');
    ans1.pb(x),ans3.pb(y),ans2.pb('+');
    assert(st.count(x)&&st.count(y));
    st.insert(x+y);
}

void op2(int x, int y){
    //print3(x,y,'^');
    ans1.pb(x),ans3.pb(y),ans2.pb('^');
    assert(st.count(x)&&st.count(y));
    st.insert(x^y);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    cur=n;
    st.insert(n);
    while(1){
        if(__builtin_popcountll(cur)==1) break;
        vec.clear();
        rep(62) if(cur&pow2(i)) vec.pb(i);
        x=inf;
        rep(sz(vec)-1) x=min(x,vec[i+1]-vec[i]);
        rep(x) op1(cur*pow2(i),cur*pow2(i));
        rep3(i,x-1,1) op1(cur*(pow2(x)-pow2(i)),cur*pow2(i-1));
        op2(cur,cur*pow2(x));
        op1(cur*(pow2(x)-1),cur^(cur*pow2(x)));
        cur=cur*(pow2(x)-1)+(cur^(cur*pow2(x)));
    }
    cur2=n;
    while(1){
        if(cur2==1) break;
        while(cur*2<cur2){
            op1(cur,cur);
            cur<<=1;
        }
        op2(cur2,cur);
        cur2^=cur;
        cur3=cur2;
        while(__builtin_popcountll(cur3)>1){
            if(cur3&cur){
                op2(cur3,cur);
                cur3^=cur;
            }
            else{
                op1(cur3,cur3);
                cur3<<=1;
            }
        }
        cur=cur3;
    }
    assert(st.count(1));
    print1(sz(ans1));
    rep(sz(ans1)) print3(ans1[i],ans2[i],ans3[i]);
    return 0;
}