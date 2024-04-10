#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int n;
vector<vector<int> > a[1111];
set<pair<int, int> > se[1111];
vector<pair<int, int> > h[1111];
vector<int> g[1111];
int reb = 0;
bool was[1111];

int cmp = 0;
void dfs(int v){
	was[v] = 1;
	cmp++;
	for (int to : g[v]) if (!was[to]) dfs(to);
}

const int p = 31;
const int p2 = 37;
const int mod = (int)1e9 + 7;

int bp(int a, int k){
	if (k == 1) return a;
	if (k % 2 == 0){
		int q = bp(a, k / 2);
		return q * (ll)q % mod;
	} else {
		return bp(a, k - 1) * (ll)a % mod;
	}
}

pair<int, int> getHash(vector<int> &a){
	int ans = 0;
	int ans2 = 0;
	for (int x : a){
		ans += bp(p, x);
		if (ans >= mod) ans -= mod;
		ans2 += bp(p2, x);
		if (ans2 >= mod) ans2 -= mod;
	}
	return mp(ans, ans2);
}

int main() {
	/*freopen("input.txt", "w", stdout);
	cout << 5000 << ' ' << 5000 << endl;
	for (int i = 0; i < 5000; i++) cout << rand() % 5000 + 1 << ' ' << rand() % 5000 + 1 << endl;
		exit(0);*/
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++){
		string s;
		cin >> s;
		s += '-';
		vector<int> now;
		int tmp = 0;
		for (int j = 0; j < s.size(); j++){
			if (s[j] >= '0' && s[j] <= '9'){
				tmp = tmp * 10 + s[j] - '0';
			} else if (s[j] == ','){
				now.pub(tmp);
				tmp = 0;
			} else if (s[j] == ':'){
				tmp = 0;
			} else if (s[j] == '-'){
				now.pub(tmp);
				tmp = 0;
				a[i].pub(now);
				now.clear();
			}
		}
		for (int j = 0; j < a[i].size(); j++){
			//sort(all(a[i][j]));
			h[i].pub(getHash(a[i][j]));
			se[i].insert(h[i][j]);
			//for (int x : a[i][j]) cout << x << ' ';
			//cout << ",";
		}
		//cout << endl;
	}

	for (int i = 1; i <= n; i++){
		int sum = bp(p, i);
		int sum2 = bp(p2, i);
		for (int j = 0; j < a[i].size(); j++){
			sum += h[i][j].x;
			sum2 += h[i][j].y;
			if (sum >= mod) sum -= mod;
			if (sum2 >= mod) sum2 -= mod;
		}
		for (int j = 0; j < a[i].size(); j++){
			sum -= h[i][j].x;
			sum2 -= h[i][j].y;
			if (sum < 0) sum += mod;
			if (sum2 < 0) sum2 += mod;
			int to = -1;
			for (int x : a[i][j]){
				if (se[x].find(mp(sum, sum2)) != se[x].end()){
					if (to == -1) to = x;
					else cout << -1, exit(0);
				}
			}
			if (to == -1) cout << -1, exit(0);
			g[i].pub(to);
			g[to].pub(i);
			reb++;
			sum += h[i][j].x;
			if (sum >= mod) sum -= mod;
			sum2 += h[i][j].y;
			if (sum2 >= mod) sum2 -= mod;
		}
	}

	dfs(1);
	if (cmp != n || reb != 2 * (n - 1)) cout << -1, exit(0);

	cout << n - 1 << "\n";
	set<pair<int, int> > wtf;
	for (int i = 0; i < n; i++) for (int to : g[i]){
		int a = i, b = to;
		if (a > b) swap(a, b);
		if (wtf.find(mp(a, b)) == wtf.end()){
			wtf.insert(mp(a, b));
			cout << a << ' ' << b << "\n";
		}
	}
}