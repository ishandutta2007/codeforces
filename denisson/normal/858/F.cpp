#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int n, m;
vector<int> g[200007];
vector<pair<pair<int, int>, int> > ans;
bool was[200007];
int h[200007];


int dfs(int v, int hh){
	if (was[v]) return -1;
	h[v] = hh;
	was[v] = 1;
	vector<int> tmp;
	for (int to : g[v]) if (h[v] < h[to]){
		auto ww = dfs(to, hh + 1);
		if (ww == -1) tmp.pub(to);
		else ans.pub(mp(mp(ww, to), v));
	}
	while(tmp.size() >= 2){
		ans.pub(mp(mp(tmp.back(), v), tmp[(int)tmp.size() - 2]));
		tmp.pop_back();
		tmp.pop_back();
	}
	if (tmp.size() == 1) return tmp[0];
	return -1;
}

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	//ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	
	for (int i = 0; i < n; i++) h[i] = n + 7;
	for (int i = 0; i < n; i++) if (!was[i]) dfs(i, 0);

	cout << ans.size() << "\n";
	for (auto c : ans) cout << c.x.x + 1 << ' ' << c.x.y + 1 << ' ' << c.y + 1 << "\n";
}