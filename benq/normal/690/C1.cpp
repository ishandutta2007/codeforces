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

vi adj[1001];
bool visit[1001];
int ans = 0;

void dfs(int node) {
    visit[node] = 1, ans++;
    for (int i: adj[node]) if (!visit[i]) dfs(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n,m; cin >> n >> m;
    F0R(i,m) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    if (m != (n-1)) {
        cout << "no";
        return 0;
    }
    dfs(1);
    if (ans<n) cout << "no";
    else cout << "yes";
}