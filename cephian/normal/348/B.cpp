#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<vector<int> > graph;

graph T;
int n;
const int N = 100005;
ll a[N];
ll need[N];

ll over = 1;
ll mnamt[N];

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	if(a >= over || b >= over)
		return over;
	ll l = (a/gcd(a,b))*b;
	if(l >= over || l < 0) return over;
	if(l % a != 0 || l % b != 0) return over;
	return l;
}

ll ml(ll a, ll b) {
	ll c = a*b;
	if(c/a == b) return c;
	return over;
}

const ll INF = 0x7fffffffffffffff;
ll ans = INF;

ll dfs(int v, int from) {
	if(T[v].size() == (v != 0)) {
		return 1;
	}
	ll l = 1;
	for(int i = 0; i < T[v].size(); ++i) {
		int u = T[v][i];
		if(u == from) continue;
		l = lcm(l, dfs(u, v));
	}
	l = ml(l, T[v].size()-(from != -1));
	ans = min(ans, a[v]/l);
	return l;
}

ll distribute(int v, int from, ll amt) {
	if(T[v].size() == (v != 0)) {
		need[v] = amt;
		return a[v]/amt;
	}
	need[v] = 0;
	ll c = INF;
	for(int i = 0; i < T[v].size(); ++i) {
		int u = T[v][i];
		if(u == from) continue;
		c = min(c, distribute(u, v, amt/(T[v].size()-(from != -1))));
	}
	return c;
}


int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		over += a[i];
	}
	T = graph(n, vector<int>());
	for(int i = 1; i < n; ++i) {
		int x,y;
		cin >> x >> y;
		T[x-1].push_back(y-1);
		T[y-1].push_back(x-1);
	}
	ll l = dfs(0, -1);
	if(l >= over) {
		cout << over-1 << "\n";
		return 0;
	}
	ll c = distribute(0, -1, l);
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += a[i] - c*need[i];
	}
	cout << ans << "\n";

	return 0;
}