#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int dp[1001][1001],par[1001],n,m,w;
map<int,vi> temp;
vector<vi> comp;
vi we, be;

int getpar(int node) {
	if (par[node] == par[par[node]]) return par[node];
	else return par[node] = getpar(par[node]);
}

void unite(int a, int b) {
	a = getpar(a), b = getpar(b);
	if (a == b) return;
	if (a>b) swap(a,b);
	par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> w;
	we.resize(n+1), be.resize(n+1);
	FOR(i,1,n+1) par[i] = i;
	FOR(i,1,n+1) cin >> we[i];
	FOR(i,1,n+1) cin >> be[i];
	F0R(i,m) {
		int x,y; cin >> x >> y;
		unite(x,y);
	}
	FOR(i,1,n+1) temp[getpar(i)].pb(i);
	vi z;
	comp.pb(z);
	for (auto a: temp) comp.pb(a.s);
	FOR(i,1,comp.size()) {
		F0R(j,1001) dp[i][j] = dp[i-1][j];
		int totalb = 0, totalw = 0;
		for (int j: comp[i]) {
			F0R(k,1001-we[j]) dp[i][k+we[j]] = max(dp[i][k+we[j]],dp[i-1][k]+be[j]);
			totalb += be[j], totalw += we[j];
		}
		if (totalw <= 1000) F0R(k,1001-totalw) dp[i][k+totalw] = max(dp[i][k+totalw],dp[i-1][k]+totalb);
	}
	cout << dp[comp.size()-1][w];
}