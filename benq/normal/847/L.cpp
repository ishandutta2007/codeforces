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

int n;
set<int> adj[1001];
ll hsh[1001];
vector<ll> nums[1001];
ll cur = 0;
map<ll,int> m;

ll hash(vi x) {
    ll ans = 0;
    for (int z: x) ans ^= hsh[z];
    return ans;
}

bool isint(int c) {
    return (int)'0' <= c && c <= (int)'9';
}

int nextint() {
    int ret = 0;
    char c; 
    while (!isint(cin.peek())) {
        if (cin.peek() == 10 || cin.peek() == 13 || cin.peek() == EOF) break;
        cin >> c;
    }
    cin >> c; ret = c-'0';
    while (isint(cin.peek())) {
        cin >> c;
        ret = 10*ret+(c-'0');
    }
    return ret;
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	cin >> n;
	FOR(i,1,n+1) {
	    hsh[i] = (((ll)rand())<<31)+rand();
	    cur ^= hsh[i];
	}
	FOR(i,1,n+1) {
	    int z = 0;
	    while (z < n-1) {
	        int t = nextint();
	        ll c = 0;
	        F0R(j,t) {
	            int t1 = nextint();
	            c ^= hsh[t1];
	        }
	        z += t;
	        nums[i].pb(c);
	        m[c] = i;
	    }
	}
}

void solve(int x) {
    for (ll y: nums[x]) {
        if (!m.count(cur^y)) {
            cout << -1;
            exit(0);
        }
        adj[x].insert(m[cur^y]);
        adj[m[cur^y]].insert(x);
    }
}

int par[1001], visit[1001];
ll val[1001];

void dfs(int no) {
    if (visit[no]) {
        cout << -1;
        exit(0);
    }
    visit[no] = 1;
    val[no] = hsh[no];
    for (int i: adj[no]) if (i != par[no]) {
        par[i] = no;
        dfs(i);
        val[no] ^= val[i];
    }
}

void test() {
    dfs(1);
    FOR(i,1,n+1) if (!visit[i]) {
        cout << -1;
        exit(0);
    }
    FOR(i,1,n+1)  {
        vector<ll> tmp; 
        for (int j: adj[i]) {
            if (j == par[i]) tmp.pb(cur^val[i]);
            else tmp.pb(val[j]);
        }
        sort(tmp.begin(),tmp.end());
        sort(nums[i].begin(),nums[i].end());
        if (tmp != nums[i]) {
            cout << -1;
            exit(0);
        }
    }
}

int main() {
	init();
	FOR(i,1,n+1) solve(i);
	test();
	cout << n-1 << "\n";
	FOR(i,1,n+1) for (int j: adj[i]) if (i < j) cout << i << " " << j << "\n";
}

// read!
// ll vs. int!