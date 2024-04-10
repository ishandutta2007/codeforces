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

int n,s; 
vector<pair<pii,int>> people;

bool ok (double mid) {
    int a1 = 0, a2 = 0;
    vector<pair<pair<ll,ll>,int>> ev; // pos, +-1, a1 or a2
    
    for (auto a: people) { // x,v,t
        double x = a.f.f, v = a.f.s;
        int t = a.s;
        if (t == 1) {
            if (x/(v+s) > mid) continue;
            if (x/v <= mid) {
                ev.pb({{0,1},1});
                ev.pb({{1000000,-1},1});
                continue;
            }
            double k = (mid-x/(v+s))/(1/v-1/(v+s));
            ll lo = x, hi = (s/v-1)*k+x;
            //cout << lo << " " << hi << "\n";
            ev.pb({{lo,1},1});
            ev.pb({{hi+1,-1},1});
        } else {
            double x1 = 1000000-x;
            if (x1/(v+s) > mid) continue;
            if (x1/v <= mid) {
                ev.pb({{0,1},2});
                ev.pb({{1000000,-1},2});
                continue;
            }
            double k = (mid-x1/(v+s))/(1/v-1/(v+s));
            ll lo = (1-s/v)*k+x, hi = x;
            //cout << "HI1 " << lo << " " << hi << "\n";
            ev.pb({{lo+1,1},2});
            ev.pb({{hi+1,-1},2});
        }
    }
    
    sort(ev.begin(),ev.end());
    for (auto a: ev) {
        if (a.s == 1) a1 += a.f.s;
        else a2 += a.f.s;
        if (a1 > 0 && a2 > 0) return 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> s;
	F0R(i,n) {
	    int x,v,t; cin >> x >> v >> t;
	    people.pb({{x,v},t});
	}
	double lo = 0, hi = 1000000;
	while (lo+0.000000001 < hi) {
	    double mid = (lo+hi)/2;
	    // cout << mid << " " << ok(mid) << "\n";
	    if (ok(mid)) hi = mid;
	    else lo = mid;
	}
	cout << fixed << setprecision(10) << lo;
}