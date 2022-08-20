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

ll n,m,q,p,ans=0;
ll dist[250][250];
bool visit[250][250];
vector<pii> visited;
char grid[250][250];

int xdir[4] = {1,0,-1,0}, ydir[4] = {0,1,0,-1};

void propogate(int x, int y) {
    int val = (grid[x][y]-'A'+1)*q;
    queue<pair<int,pii>> todo; todo.push({val,{x,y}}); 
    visit[x][y] = 1; visited.pb({x,y});
    dist[x][y] += val;
    
    while (todo.size()) {
        auto a = todo.front(); todo.pop();
        F0R(i,4) {
            int nx = a.s.f+xdir[i], ny = a.s.s+ydir[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '*' || visit[nx][ny]) continue;
            visit[nx][ny] = 1; visited.pb({nx,ny});
            dist[nx][ny] += a.f/2;
            if (a.f/2 != 0) todo.push({a.f/2,{nx,ny}});
        }
    }
    for (auto a: visited) visit[a.f][a.s] = 0;
    visited.clear();
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q >> p;
	F0R(i,n) F0R(j,m) cin >> grid[i][j];
	F0R(i,n) F0R(j,m) if (grid[i][j] != '.' && grid[i][j] != '*') {
	    propogate(i,j);
    	/*F0R(i,n) {
    	    F0R(j,m) cout << dist[i][j] << " ";
    	    cout << "\n";
    	}
    	cout << "\n";*/
	}
	F0R(i,n) F0R(j,m) if (dist[i][j] > p) ans++;
	cout << ans;
}

// read!
// ll vs. int!