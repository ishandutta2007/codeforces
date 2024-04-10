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
const int maxn=2005;
//i_am_noob
int n,minid;
string str;
vector<int> vec;
bool vis[maxn]={false};

template <typename T>
struct Point{
    T x,y;
    Point(const T _x=T(0), const T _y=T(0)): x(_x),y(_y){}
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

Point<int> a[maxn],minn(inf,0),P,v;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> a[i].x >> a[i].y;
    cin >> str;
    rep(n) if(a[i]<minn){
        minn=a[i],minid=i;
    }
    vec.pb(minid);
    vis[minid]=true;
    rep(n-2){
        P=a[vec.back()];
        if(i) v=P-a[vec[sz(vec)-2]];
        else v=P-Point<int>(P.x+1,-4e9);
        if(str[i]=='R'){
            rep1(j,n) if(!vis[j]) if((v^(a[j]-P))<=0){
                v=-v;
                break;
            }
            rep1(j,n) if(!vis[j]) if((v^(a[j]-P))>0){
                v=a[j]-P;
                minid=j;
            }
        }
        else{
            rep1(j,n) if(!vis[j]) if((v^(a[j]-P))>=0){
                v=-v;
                break;
            }
            rep1(j,n) if(!vis[j]) if((v^(a[j]-P))<0){
                v=a[j]-P;
                minid=j;
            }
        }
        vec.pb(minid);
        vis[minid]=true;
    }
    rep(n) if(!vis[i]) vec.pb(i);
    rep(n) print0(vec[i]+1);
    cout << "\n";
    return 0;
}