#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define int ll
#define ull unsigned ll
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define chkmin(a,b) (a=min(a,b))
#define chkmax(a,b) (a=max(a,b))
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
//#define inf 1010000000
#define inf 4000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#ifdef i_am_noob
#define bug(...) cerr << "#" << __LINE__ << ' ' << #__VA_ARGS__ << "- ", _do(__VA_ARGS__)
template<typename T> void _do(vector<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(unordered_set<T> x){for(auto i: x) cerr << i << ' ';cerr << "\n";}
template<typename T> void _do(T && x) {cerr << x << endl;}
template<typename T, typename ...S> void _do(T && x, S&&...y) {cerr << x << ", "; _do(y...);}
#else
#define bug(...) 777771449
#endif
template<typename T> void print(T && x) {cout << x << "\n";}
template<typename T, typename... S> void print(T && x, S&&... y) {cout << x << ' ';print(y...);}

const int maxn=2505;

//i_am_noob
//#define wiwihorz  
struct point{
    int x,y;
};
 
point operator -(const point& p1, const point& p2){return {p1.x-p2.x,p1.y-p2.y};}
bool operator <(const point& p1, const point& p2){return p1.x==p2.x?p1.y<p2.y:p1.x<p2.x;}
int operator ^(const point& p1, const point& p2){return p1.x*p2.y-p1.y*p2.x;}//cross
 
int ori(const point& p1, const point& p2, const point& p3){return (p2-p1)^(p3-p1);}

bool angle_comp(const point& p1, const point& p2){
    bool de1=p1.y>0||(p1.y==0&&p1.x>=0);
    bool de2=p2.y>0||(p2.y==0&&p2.x>=0);
    if(de1&&!de2) return 1;
    if(de2&&!de1) return 0;
    return (p1^p2)>0;
}

int n,nxt[maxn],pre[maxn],res;
point p[maxn];

void orzck(){
    cin >> n;
    rep(n) cin >> p[i].x >> p[i].y;
    rep(n){
        vector<point> vec;
        rep1(j,n) if(i!=j) vec.pb(p[j]-p[i]);
        sort(all(vec),angle_comp);
        int cur=0;
        rep1(j,sz(vec)){
            while(cur+1<sz(vec)&&(vec[j]^vec[cur+1])>0) cur++;
            while(cur<j) cur++;
            nxt[j]=cur;
        }
        cur=0;
        rep1(j,sz(vec)){
            while(cur<j&&(vec[cur]^vec[j])<=0) cur++;
            pre[j]=cur;
        }
        rep1(j,sz(vec)) res+=(nxt[j]-j)*(j-pre[j]);
        rep1(j,sz(vec)) res-=(nxt[j]-j)*(nxt[j]-j-1)/2;
        rep1(j,sz(vec)) bug(j,nxt[j],pre[j]);
        bug(res);
    }
    print(res*(n-4)/2);
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cout << fixed << setprecision(15);
    int t;
    #ifdef wiwihorz
    cin >> t;
    #else
    t=1;
    #endif
    ld start=clock();
    while(t--) orzck();
    bug((clock()-start)/CLOCKS_PER_SEC);
    return 0;
}