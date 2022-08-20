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

int n,m,k, dist[1000][1000];
bool done[2][1000][1000];
char grid[1000][1000];
queue<pii> todo;

int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};

void process(pii x) {
    // cout << x.f << " " << x.s << "\n";
    F0R(j,4) FOR(i,1,k+1) {
        pii x1 = {x.f+i*xdir[j], x.s+i*ydir[j]};
        if (x1.f < 0 || x1.f >= n || x1.s < 0 || x1.s >= m) break;
        if (grid[x1.f][x1.s] == '#') break;
        if (done[j&1][x1.f][x1.s]) break;
        
        done[j&1][x1.f][x1.s] = 1;
        if (dist[x.f][x.s]+1 < dist[x1.f][x1.s]) {
            dist[x1.f][x1.s] = dist[x.f][x.s]+1;
            // cout << "HI " << x.f << " " << x.s << " " << x1.f << " " << x1.s << "\n";
            todo.push(x1);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	F0R(i,n) F0R(j,m) cin >> grid[i][j];
	F0R(i,n) F0R(j,m) dist[i][j] = MOD;
	int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
	x1 --, y1 --, x2 --, y2 --;
	dist[x1][y1] = 0;
	todo.push({x1,y1});
	while (todo.size()) {
	    pii x = todo.front(); todo.pop();
	    process(x);
	}
	if (dist[x2][y2] == MOD) cout << -1;
	else cout << dist[x2][y2];
}

// read!
// ll vs. int!