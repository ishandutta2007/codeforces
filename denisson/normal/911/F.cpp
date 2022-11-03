#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<int> g[200007];

pair<int, int> dfs(int v, int pred){
	pair<int, int> ans = mp(0, v);
	for (auto to : g[v]) if (to != pred){
		ans = max(ans, dfs(to, v));
	}
	ans.x++;
	return ans;
}

int v1, v2;
vector<int> st, path;
void dfs2(int v, int pred){
	st.pub(v);
	if (v == v2) path = st;
	for (auto to : g[v]) if (to != pred) dfs2(to, v);
	st.pop_back();
}

ll sum;

vector<int> pp;
void dfs3(int v, int pred, int len){
	sum += len;
	for (int to : g[v]) if (to != pred) dfs3(to, v, len + 1);
	pp.pub(v);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	auto now = dfs(0, -1);
	auto now2 = dfs(now.y, -1);
	v1 = now.y, v2 = now2.y;
	dfs2(v1, -1);
	set<int> se;
	for (int x : path) se.insert(x);
	ll ww = 0;
	vector<pair<pair<int, int>, int> > ans;
	for (int i = 0; i < path.size(); i++){
		pp.clear();
		sum = 0;
		for (int to : g[path[i]]) if (se.find(to) == se.end()){
			dfs3(to, path[i], 1);
		}
		ww += sum;
		int now = path.back();
		int val = path.size() - i - 1;
		if (i >= path.size() / 2) now = path[0], val = i;
		for (auto v : pp) ans.pub(mp(mp(v, now), v)), ww += val;
	}
	for (int i = 0; i < path.size() - 1; i++) ans.pub(mp(mp(path[i], path.back()), path[i])), ww += path.size() - i - 1;
	cout << ww << endl;
	for (auto c : ans) cout << c.x.x + 1 << ' ' << c.x.y + 1 << ' ' << c.y + 1<< "\n";
}