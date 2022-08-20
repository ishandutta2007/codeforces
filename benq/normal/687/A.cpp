#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define piii pair<pii, int>
#define vi vector<int>
#define vpii vector<pii>

#define read1(a) int a; scanf("%d", &a)
#define read2(a, b) int a, b; scanf("%d %d", &a, &b)
#define read3(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define readgi(n) F0R(i, n) { scanf("%d", &arr[i]); }
#define readgs(n) F0R(i, n) { scanf(" %c", &arr[i]); }

#define f first
#define s second

#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);

#define println1(a) printf("%d\n", a);
#define println2(a, b) printf("%d %d\n", a, b);
#define println3(a, b, c) printf("%d %d %d\n", a, b, c);
#define pv(v) for (int i : v) { printf("%d ", i); } printf("\n");

const int MOD = 1000000007;
const int MAX = 100005;

vi g[MAX];

int colour[MAX], a,b;
bool visited[MAX], wrong;


void dfs(int a) {
	visited[a] = 1;
	for (int i=0; i < g[a].size(); i++) {
		if (visited[g[a][i]] == 0) {
			colour[g[a][i]] = 1 - colour[a];
			dfs(g[a][i]);
		}
		else if (colour[g[a][i]] == colour[a]) wrong = 1;
	}
}


int main() {
    cin >> a >> b;

    for (int i=0; i<b; i++) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    vi ca;
    vi cb;
    FOR(i, 1, a+1) { if (!visited[i]) { dfs(i); } }
    if (wrong) { cout << -1 << endl; return 0; }
    FOR(i, 1, a+1) { if (colour[i] == 1) { ca.pb(i); } else { cb.pb(i); } }
    cout << ca.size() << endl;
    pv(ca);
    cout << cb.size() << endl;
    pv(cb);
	return 0;
}