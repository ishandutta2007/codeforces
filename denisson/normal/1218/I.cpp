#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector <vector <int> > gr, rev_gr;

int n;

void add_edge(int v, int u) {
	//cout << v << " " << u << "\n";
	gr[(v >= 2 * n ? v - 2 * n : v + 2 * n)].push_back(u);
	gr[(u >= 2 * n ? u - 2 * n : u + 2 * n)].push_back(v);
}


vector <bool> used;
vector <int> order;

void dfs(int v) {
	if (used[v]) return;
	used[v] = true;
	for (int u : gr[v]) {
		dfs(u);
	}
	order.push_back(v);
}

vector <int> comp;
int cnt;

void rev_dfs(int v) {
	if (comp[v]) return;
	comp[v] = cnt;
	for (int u : rev_gr[v]) {
		rev_dfs(u);
	}
}

vector <int> tout;
int timer = 0;
vector <vector <int> > new_gr;
	
void dfs_tout(int v) {
	if (used[v]) return;
	used[v] = true;
	for (int u : new_gr[v]) {
		dfs_tout(u);
	}
	tout[v] = timer++;
}

void condense() {
	int sz = gr.size();
	used.clear();
	order.clear();
	used.resize(sz, false);
	for (int i = 0; i < sz; i++) {
		if (used[i]) continue;
		dfs(i);
	}

	reverse(order.begin(), order.end());

	comp.clear();
	comp.resize(sz, 0);

	cnt = 1;

	rev_gr.clear();
	rev_gr.resize(sz);
	for (int i = 0; i < sz; i++) {
		for (int u : gr[i]) {
			rev_gr[u].push_back(i);
		}
	}

	for (int v : order) {
		if (comp[v]) continue;
		rev_dfs(v);
		cnt++;
	}

/*	for (int x : comp) {
		cout << x << " ";
	}
	cout << "\n";*/

	vector <int> res;

	for (int i = 0; i < 2 * n; i++) {
		if (comp[i] == comp[i + 2 * n]) {
			cout << "-1\n";
			exit(0);
		}
	}

	new_gr.resize(cnt);
	for (int v = 0; v < sz; v++) {
		for (int u : gr[v]) {
			if (comp[v] != comp[u]) {
				new_gr[comp[v]].push_back(comp[u]);
			}
		}
	}

	used.clear();
	used.resize(cnt);
	tout.clear();
	tout.resize(cnt);
	timer = 0;

	for (int i = 0; i < cnt; i++) {
		if (used[i]) continue;
		dfs_tout(i);
	}	

	for (int i = 0; i < 2 * n; i++) {
		int v = comp[i], u = comp[i + 2 * n];
		if (tout[v] < tout[u]) {
			res.push_back(i);
		}
	}

	cout << res.size() << "\n";
	for (int x : res) {
		if (x < n) {
			cout << "row ";
		} else {
			cout << "col ";
		}
		cout << x % n << "\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector <vector <int> > a(n, vector <int> (n, 0));
	vector <vector <int> > b(n, vector <int> (n, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			b[i][j] = s[j] - '0';
		}
	}
	string s;
	cin >> s;
	vector <int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = s[i] - '0';
	}
	gr.resize(4 * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int ax = 0; ax < 2; ax++) {
				for (int ay = 0; ay < 2; ay++) {
					int was = a[i][j];
					if (ax) {
						was ^= d[j];
					}
					if (ay) {
						was ^= d[i];
					}
					if (was != b[i][j]) {
						//cout << i << " " << j << " " << ax << " " << ay << "\n";
						add_edge((ax ? i + 2 * n : i), (ay ? j + 3 * n : j + n));
					}
				}
			}
		}
	}
	condense();
}