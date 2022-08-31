#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n,w,h;
vector<pair<int,pii>> d[2][200000];
pii ans[100000];

bool comp (pair<int,pii> a, pair<int,pii> b) {
    return a.s.f < b.s.f;    
}

void process(int ind) {
    sort(d[0][ind].begin(),d[0][ind].end(),comp); // vertical
    sort(d[1][ind].begin(),d[1][ind].end(),comp); // horizontal
    
    F0R(i,d[0][ind].size()) {
        pii z = mp(i,0);
        int x = min((int)d[0][ind].size()-1-i,(int)d[1][ind].size()-1);
        z.f += x, z.s += x;
        if (z.f == d[0][ind].size()-1) ans[d[0][ind][i].f] = {w,d[1][ind][z.s].s.f};
        else ans[d[0][ind][i].f] = {d[0][ind][z.f+1].s.f,h};
    }
    
    F0R(i,d[1][ind].size()) {
        pii z = mp(0,i);
        int x = min((int)d[0][ind].size()-1,(int)d[1][ind].size()-1-i);
        z.f += x, z.s += x;
        if (z.s == d[1][ind].size()-1) ans[d[1][ind][i].f] = {d[0][ind][z.f].s.f,h};
        else ans[d[1][ind][i].f] = {w,d[1][ind][z.s+1].s.f};
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> w >> h;
	F0R(i,n) {
	    int g,p,t; cin >> g >> p >> t;
	    d[g-1][t-p+100000].pb({i,{p,t}});
	}
	F0R(i,200000) process(i);
	F0R(i,n) cout << ans[i].f << " " << ans[i].s << "\n";
}

// read!
// ll vs. int!