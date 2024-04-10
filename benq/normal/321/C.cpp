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

int N, visit[100001], sub[100001], par[100001];
char ans[100001];
vi adj[100001];

void dfs (int no) {
    sub[no] = 1;
    for (int i: adj[no]) if (!visit[i] && i != par[no]) {
        par[i] = no;
        dfs(i);
        sub[no] += sub[i];
    }
}

int get_centroid(int x) {
    par[x] = 0;
    dfs(x);
    int sz = sub[x];
    while (1) {
        pii mx = {0,0};
        for (int i: adj[x]) if (!visit[i] && i != par[x]) mx = max(mx,{sub[i],i});
        if (mx.f*2 > sz) x = mx.s;
        else return x;
    }
}

void solve (int x, char c) {
    x = get_centroid(x);
    ans[x] = c; visit[x] = 1;
    for (int i: adj[x]) if (!visit[i]) solve(i,c+1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	F0R(i,N-1) {
	    int a,b; cin >> a >> b;
	    adj[a].pb(b), adj[b].pb(a);
	}
	solve(1,'A');
	FOR(i,1,N+1) cout << ans[i] << " ";
}

// read!
// ll vs. int!