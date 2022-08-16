#include <bits/stdc++.h>
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define cin_desync()                      \
	do {                                  \
		ios_base::sync_with_stdio(false); \
		cin.tie(0);                       \
	} while (0)                           \

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

void fail() {
	cout << "NO" << endl;
	exit(0);
}

void succ(vector<int> &a, vector<int> &b) {
	cout << "YES" << endl;
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ' ' << b[i] << '\n';
	}
	exit(0);
}

void insert(int d, int n, vector<int> &a, vector<int> &b);

const int max_N = 1e5 + 10;
const ll inf = 1e9 + 45;
int dist[max_N];
int pedge[max_N];
bool popped[max_N];

int main() {
	int n;
	cin >> n;
	int cpy = n;

	vector<int> pf;
	int R = sqrt(n);
	for (int p = 2; p <= R; ++p) {
		if (n % p == 0) {
			pf.push_back(p);
		}
		while(n % p == 0) {
			n /= p;
		}
	}
	if (n > 1) {
		pf.push_back(n);
	}

	if (pf.size() == 1) {
		fail();
	}

	int p = pf[0];
	for (int i = 1; i < p; ++i) {
		dist[i] = inf;
	}

	priority_queue<pii, vector<pii>, greater<pii>> dfq;
	dfq.push({0, 0});

	while(!dfq.empty()) {
		int u = dfq.top().second;
		dfq.pop();

		if (popped[u]) {
			continue;
		}
		popped[u] = true;

		for (auto &e : pf) {
			int v = (e + u) % p;
			if (dist[v] > dist[u] + e) {
				pedge[v] = e;
				dist[v] = dist[u] + e;
				dfq.push({dist[v], v});
			}
		}
	}

	for (int u = 0; u < p; ++u) {
		trace(u, dist[u]);
	}

	int r = (cpy - 1) % p;
	if (dist[r] > cpy - 1) {
		fail();
	}

	map<int, int> cache;
	for (int q = r; q > 0; q = (q - (pedge[q] % p) + p) % p) {
		cache[pedge[q]]++;
	}

	vector<int> a, b;
	for (auto &q : cache) {
		insert(q.second * q.first, cpy, a, b);
	}

	if (dist[r] != cpy - 1) {
		insert(cpy - 1 - dist[r], cpy, a, b);
	}

	succ(a, b);
}

void insert(int d, int n, vector<int> &a, vector<int> &b)
{
	trace(d, n);
	int g = gcd(d, n);
	a.push_back(d / g);
	b.push_back(n / g);
}