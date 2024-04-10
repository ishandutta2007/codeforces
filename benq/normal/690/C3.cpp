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

int depth[200001],par[200001][18],a=1,b=1,c=0;

int lca(int v1, int v2) {
	if (depth[v1]>depth[v2]) swap(v1,v2);
	int z = depth[v2]-depth[v1];
	F0R(i,18) if (z & (1<<i)) v2 = par[v2][i];
	if (v1 == v2) return v1;
	for (int i = 17; i >= 0; --i) {
		if (par[v1][i] != par[v2][i]) v1 = par[v1][i], v2 = par[v2][i];
	}
	return par[v1][0];
}

int dist(int v1, int v2) {
	int ans = 0;
	int z = lca(v1,v2);
	return (depth[v1]+depth[v2]-2*depth[z]);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,2,n+1) {
		cin >> par[i][0];
		depth[i] = depth[par[i][0]]+1;
		FOR(j,1,18) par[i][j] = par[par[i][j-1]][j-1];
		int c1 = dist(a,i), c2 = dist(b,i);
		if (c1 > c && c1 >= c2) c++,b = i;
		else if (c2 > c && c2 > c1) c++,a = i;
		cout << c << " ";
	}
}