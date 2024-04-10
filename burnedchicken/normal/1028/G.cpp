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
const int maxn=205;
//i_am_noob
int l=1,r=10004205361450474,x=100020001,y=20468427,k;
vector<int> vec;

void query(int l, int r){
    int tmp=min(10000ll,l),res;
    int tmp1=(r+2-l)/(tmp+1);
    int tmp2=(r+2-l)%(tmp+1);
    if(r-l+1<tmp){
        print0(r-l+1);
        rep2(i,l,r+1) print0(i);
        cout << endl;
        cin >> res;
        exit(0);
    }
    vector<int> vec;
    vec.pb(l-1);
    rep(tmp2) vec.pb(vec.back()+tmp1+1);
    rep(tmp-tmp2) vec.pb(vec.back()+tmp1);
    print0(tmp);
    rep2(i,1,tmp+1) print0(vec[i]);
    cout << endl;
    cin >> res;
    if(res==-1) exit(0);
    if(res==tmp){
        l=vec[tmp]+1;
        query(l,r);
    }
    query(vec[res]+1,vec[res+1]-1);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    print2(1,2047*x+y);cout << flush;
    cin >> k;
    if(k==-1) return 0;
    if(k==1){
        l=2047*x+y+1;
        query(2047*x+y+1,10004205361450474);
    }
    print2(1,2046);cout << flush;
    cin >> k;
    if(k==-1) return 0;
    if(k==1){
        print0(2047);
        rep(2047) print0(x*i+y);
        cout << endl;
        cin >> k;
        if(k==-1) return 0;
        if(k==0){
            print0(2047);
            vec.clear();
            vec.pb(4094),vec.pb(8190),vec.pb(16382);
            rep(2044) vec.pb((i+1)*10001+16382);
            rep(2047) print0(vec[i]);
            cout << endl;
            cin >> k;
            if(k==-1) return 0;
            if(k==2047) query(vec[k-1]+1,y-1);
            if(k==0) query(2047,vec[0]-1);
            query(vec[k-1]+1,vec[k]-1);
        }
        query((k-1)*x+y+1,k*x+y-1);
    }
    print2(1,6);cout << flush;
    cin >> k;
    if(k==-1) return 0;
    if(k==1){
        print0(7);
        rep(7) print0(pow2(4+i)-2);
        cout << endl;
        cin >> k;
        if(k==-1) return 0;
        query(pow2(3+k)-1,pow2(4+k)-3);
    }
    print2(1,2);cout << flush;
    cin >> k;
    if(k==-1) return 0;
    if(k==1){
        print4(3,3,4,5);cout << flush;
        cin >> k;
        return 0;
    }
    print2(1,1);cout << flush;
    cin >> k;
    return 0;
}