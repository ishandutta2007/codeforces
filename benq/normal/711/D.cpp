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

int n, e, comp[200001];
ll z;
vi adj[200001];

ll po(ll a, int b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans*a % MOD;
		a = a*a % MOD;
		b /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	FOR(i,1,n+1) {
		int x; cin >> x;
		adj[i].pb(x); adj[x].pb(i);
	}
	queue<int> todo;
	FOR(i,1,n+1) if (adj[i].size() == 1) todo.push(i);
	while (todo.size()) {
		int x = todo.front(); todo.pop();
		for (int i: adj[x]) {
			adj[i].erase(find(adj[i].begin(),adj[i].end(),x));
			adj[x].erase(find(adj[x].begin(),adj[x].end(),i));
			if (adj[i].size() == 1) todo.push(i);
		}
		e++;
	}
	z = po(2,e);
	int n1 = 0;
	FOR(i,1,n+1) if (comp[i] == 0 && adj[i].size()) {
	    comp[i] = (++n1);
		int h = adj[i][0];
		int cur = i, par = h, co = 1;
		comp[par] = n1;
		if (adj[i][0] == adj[i][1]) {
			z = 2*z % MOD;
			continue;
		}
		while (cur != h) {
			int c1 = cur; comp[c1] = n1;
			for (int q: adj[cur]) if (q != par) {
				cur = q;
				break;
			}
			par = c1;
			co++;
		}
		z = z*(po(2,co)-2) % MOD;
 	}
	cout << z;
}