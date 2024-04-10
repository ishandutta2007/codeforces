#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int p[1000001], par[1000001], ans[1000001], size[1000001];
vi z1[1000001], z2[1000001];

int getpar(int node) {
	int x = par[node];
	if (par[x] != x) return par[node] = getpar(x);
	return x;
}

void merge(int a, int b) {
	if (size[a] < size[b]) swap(a,b);
	par[b] = a;
	size[a] += size[b];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m; cin >> n >> m;
	FOR(i,1,n+1) {
		cin >> p[i];
		size[i] = 1;
		par[i] = i;
	}
	F0R(i,m) {
		int a, b; cin >> a >> b;
		if (getpar(a) != getpar(b)) merge(getpar(a),getpar(b));
	}
	FOR(i,1,n+1) {
		z1[getpar(i)].pb(p[i]);
		z2[getpar(i)].pb(i);
	}
	FOR(i,1,n+1) if (getpar(i) == i) {
		sort (z1[i].begin(),z1[i].end());
		F0R(j,z1[i].size()) {
			ans[z2[i][z1[i].size()-1-j]] = z1[i][j];
		}
	}
	FOR(i,1,n+1) cout << ans[i] << " ";
	return 0;
}