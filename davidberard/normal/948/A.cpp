#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int R, C;
	cin >> R >> C;
	vector<string> grid(R);
	for(string& ss: grid) cin >> ss;

	vector<pii> wolves;
	for(int i=0;i<R;++i) {
		for(int j=0;j<C;++j) {
			if(grid[i][j] == 'W')
				wolves.push_back(pii(i, j));
		}
	}

	vector<string> newGrid(grid);
	bool bad = false;

	stack<pii> ops;
	for(int i=0;i<wolves.size() && !bad;++i) {
		pii w = wolves[i];
		pii left = pii(w.first, w.second-1);
		pii right = pii(w.first, w.second+1);
		pii up = pii(w.first-1, w.second);
		pii down = pii(w.first+1, w.second);
		ops.push(left); ops.push(right); ops.push(up); ops.push(down);
		while(!ops.empty()) {
			pii t = ops.top();
			ops.pop();
			if(t.first < 0 || t.second < 0 || t.first >= R || t.second >= C)
				continue;
			if(grid[t.first][t.second] == 'S')
				bad = true;
			else if(newGrid[t.first][t.second] == '.')
				newGrid[t.first][t.second] = 'D';
		}
	}

	if(bad) cout << "No" << endl;
	else {
		cout << "Yes\n";
		for(int i=0;i<R;++i)
			cout << newGrid[i] << "\n";

	}

	return 0;
}