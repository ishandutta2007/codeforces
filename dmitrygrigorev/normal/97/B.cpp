#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

set<pair<int, int> > v;
vector<pair<int, int> > add;

void solve(vector<pair<int, int> > cur){
	if (cur.size() <= 1) return;
	vector<int> xc;
	for (int i=0; i < cur.size(); ++i) xc.push_back(cur[i].first);
	sort(xc.begin(), xc.end());
	int X = xc[xc.size() / 2];
	vector<pair<int, int> > l, r;
	for (int i=0; i < cur.size(); ++i){
		int xx = X, yy = cur[i].second;
		if (!v.count({xx, yy})){
			v.insert({xx, yy});
			add.push_back({xx, yy});
		}
		if (cur[i].first < X) l.push_back(cur[i]);
		if (cur[i].first > X) r.push_back(cur[i]);
	}
	solve(l);
	solve(r);
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int> > cur;

	for (int i=0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		cur.push_back({x, y});
		v.insert({x, y});
		add.push_back({x, y});
	}

	solve(cur);
	cout << add.size() << endl;
	for (int i=0; i < add.size(); ++i) cout << add[i].first << " " << add[i].second << endl;

}