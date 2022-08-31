#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vi adj[100001];
bool visit[100001];
int ans = 0, best[100001];

void dfs(int node) {
	visit[node] = 1;
	vi b;
	for (int i: adj[node]) if (!visit[i]) {
		dfs(i);
		b.pb(best[i]+1);
	}
	sort(b.begin(),b.end());
	if (b.size() == 0) return;
	else if (b.size() == 1) {
		ans = max(ans,b[0]);
		best[node] = b[0];
	} else {
		ans = max(ans,b[b.size()-1]+b[b.size()-2]);
		best[node] = b[b.size()-1];
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    int n,m; cin >> n >> m;
    F0R(i,m) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    dfs(1);
    cout << ans;
}