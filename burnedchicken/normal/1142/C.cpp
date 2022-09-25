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
const int maxn=100005;
//i_am_noob
int n;

template <typename T>
struct Point{
    T x,y;
    Point(): x(0),y(0){}
    Point(const T _x, const T _y): x(_x),y(_y){}
    Point operator +(const Point& o) const {return Point(x+o.x,y+o.y);}
    Point operator -(const Point& o) const {return Point(x-o.x,y-o.y);}
    Point operator *(const int& o) const {return Point(x*o,y*o);}
    T operator &(const Point& o) const {return x*o.x+y*o.y;}
    T operator ^(const Point& o) const {return x*o.y-y*o.x;}
    bool operator ==(const Point& o) const {return x==o.x&&y==o.y;}
    bool operator <(const Point& o) const {return x==o.x?y<o.y:x<o.x;}
    Point operator -(){return Point(-x,-y);}
    T len(){return *this&*this;}
};

Point<int> a[maxn],P,Q;
vector<Point<int>> vec,vec1;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i].x >> a[i].y;
    sort(a,a+n);
    reverse(a,a+n);
    rep(n) if(vec.empty()||vec.back().x>a[i].x) vec.pb(a[i]);
    reverse(all(vec));
    rep(sz(vec)){
        while(1){
            if(sz(vec1)<=1){
                vec1.pb(vec[i]);
                break;
            }
            P=vec1.back();Q=vec1[sz(vec1)-2];
            if(vec[i].y*(P.x-Q.x)>=vec[i].x*vec[i].x*(P.x-Q.x)+(P.y-Q.y-P.x*P.x+Q.x*Q.x)*vec[i].x+P.x*Q.y-Q.x*P.y+P.x*Q.x*(P.x-Q.x)) vec1.pop_back();
            else{
                vec1.pb(vec[i]);
                break;
            }
        }
    }
    print1(sz(vec1)-1);
    return 0;
}