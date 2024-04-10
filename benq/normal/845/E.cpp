/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,m,k,mid;
vector<pii> p;
map<int,int> x, y;
vi rx, ry;
int cum[1005][1005];

bool posi() {
    memset (cum,0,sizeof cum);
    x.clear(), y.clear(); rx.clear(), ry.clear();
    x[0] = x[1] = x[n+1] = y[0] = y[1] = y[m+1] = 0;
    vector<pair<pii,pii>> rect;
    F0R(i,k) rect.pb({{max(p[i].f-mid,1),min(p[i].f+mid,n)},{max(p[i].s-mid,1),min(p[i].s+mid,m)}});
    for (auto a: rect) x[a.f.f] = x[a.f.s+1] = y[a.s.f] = y[a.s.s+1] = 0;
    
    int co = 0;
    for (auto& a: x) {
        a.s = co++;
        rx.pb(a.f);
    }
    co = 0;
    for (auto& a: y) {
        a.s = co++;
        ry.pb(a.f);
    }
    
    for (auto& a: rect) {
        a = {{x[a.f.f],x[a.f.s+1]},{y[a.s.f],y[a.s.s+1]}};
        cum[a.f.s][a.s.s] ++, cum[a.f.f][a.s.f] ++;
        cum[a.f.s][a.s.f] --, cum[a.f.f][a.s.s] --;
        //cout << "HI " << a.f.f << " " << a.f.s << " " << a.s.f << " " << a.s.s << "\n";
    }
    
    int minx = MOD, maxx = -MOD, miny = MOD, maxy = -MOD;
    FOR(i,1,x.size()-1) FOR(j,1,y.size()-1) {
        cum[i][j] += cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1];
        if (cum[i][j] == 0) {
            minx = min(minx,rx[i]);
            maxx = max(maxx,rx[i+1]-1);
            miny = min(miny,ry[j]);
            maxy = max(maxy,ry[j+1]-1);
        }
    }
    return maxx-minx <= 2*mid && maxy-miny <= 2*mid;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	F0R(i,k) {
	    int x,y; cin >> x >> y; 
	    p.pb({x,y});
	}
	int lo = 0, hi = 1000000000;
	while (lo < hi) {
	    mid = (lo+hi)/2;
	    if (posi()) hi = mid;
	    else lo = mid+1;
	}
	cout << lo;
} 

// read!
// ll vs. int!