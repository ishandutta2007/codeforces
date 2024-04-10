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
vector<pii> todo;
vi t;

int getpar(int node) {
	if (par[par[node]] == par[node]) return par[node];
	else return par[node] = getpar(par[node]);
}

void unite(int a, int b) {
	if (getpar(a) == getpar(b)) {
		todo.pb(mp(a,b));
		return;
	}
	a = getpar(a), b = getpar(b);
	if (a>b) swap(a,b);
	par[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	FOR(i,1,n+1) par[i] = i;
	F0R(i,n-1) {
		int a,b; cin >> a >> b;
		unite(a,b);
	}
	FOR(i,1,n+1) if (getpar(i) == i) t.pb(i);
	cout << t.size()-1 << "\n";
	F0R(i,t.size()-1) {
		cout << todo[i].f << " " << todo[i].s << " " << t[i] << " " << t[i+1] << "\n";
	}
	return 0;
}