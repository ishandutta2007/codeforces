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

int par[1001];
bool ispar[1001];
vi pars;
map<int,int> comp;

int getpar(int node) {
	if (par[node] == par[par[node]]) return par[node];
	else return par[node] = getpar(par[node]);
}

void merge(int a, int b) {
	a = getpar(a), b = getpar(b);
	if (a == b) return;
	if (a>b) swap(a,b);
	if (ispar[a]) par[b] = a;
	else if (ispar[b]) par[a] = b;
	else par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,k; cin >> n >> m >> k;
	FOR(i,1,n+1) par[i] = i;
	F0R(i,k) {
		int x; cin >> x;
		ispar[x] = 1;
	}
	F0R(i,m) {
		int u,v; cin >> u >> v;
		merge(u,v);
	}
	FOR(i,1,n+1) comp[getpar(i)] ++;
	int z = 0;
	vi stuff;
	for (auto a: comp) if (ispar[a.f]) stuff.pb(a.s);
	else z += a.s;
	sort(stuff.begin(),stuff.end());
	stuff[stuff.size()-1] += z;
	int ans = 0;
	for (int i: stuff) ans += i*(i-1)/2;
	cout << ans-m;
}