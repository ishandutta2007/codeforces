#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<string> ans;

bool cmp(vector<int> &a, vector<int> &b){
	return (a.size() < b.size());
}

void dvd(vector<vector<int> > &cur_sets, int x, int tet) {
	sort(cur_sets.begin(), cur_sets.end(), cmp);

	int u = 0;
	while (cur_sets.back().size() < x) {
		for (int i=0; i < cur_sets[u].size(); ++i){
			ans[cur_sets[u][i]][tet] = '1';
			//cout << u << " " << i << " " << cur_sets[u][i] << endl;
		}
		x -= cur_sets[u].size();
		u++;
	}

	if (cur_sets.back().size() == x) {
		ans[cur_sets[u][0]][tet] = '1';
		x--;
	}

	for (int i=0; i < x; ++i){
		ans[cur_sets.back()[i]][tet] = '1';
	}
	vector<int> dop;
	for (int i=x; i < cur_sets.back().size(); ++i){
		dop.push_back(cur_sets.back()[i]);
	}
	while (cur_sets.back().size() > x) cur_sets.back().pop_back();
	cur_sets.push_back(dop);
	//cout << "=========\n";

}

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i=0; i < n; ++i) cin >> v[i];

	for (int i=0; i < n+1; ++i){
		string t = "";
		for (int j=0;j<n;++j) t += '0';
		ans.push_back(t);
	}

	vector<vector<int> > cur_sets = {{}};

	for (int i=0; i < n+1; ++i){
		cur_sets[0].push_back(i);
	}

	for (int i=0; i < n; ++i){
		dvd(cur_sets, v[i], i);
	}

	cout << n+1 << endl;
	for (int i=0;i<n+1;++i){
		for (int j=0; j < n; ++j) cout << ans[i][j];
		cout << endl;
	}




}