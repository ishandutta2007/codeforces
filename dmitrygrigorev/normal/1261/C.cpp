#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#include <ext/pb_ds/assoc_container.hpp> //  . 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

vector<pair<int, int> > dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

int n, m;


bool check(vector<vector<int> > &d, vector<vector<char> > &matrix, int x, vector<vector<int> > &spec){

	queue<pair<int, int> > q;

	for (int i=0;i<n;++i) for (int j=0;j<m;++j){
		spec[i][j] = 1e9;
	}

	for (int i=0; i < n; ++i) for (int j=0;j<m;++j){
		if (matrix[i][j] != '.' && d[i][j] >= x){
			q.push({i, j});
			spec[i][j] = 0;
		}
	}


	//cout << "=== " << x << " " << q.size() << endl;

	while (q.size()){
		pair<int, int> W = q.front();
		q.pop();
		for (int e=0; e < 8; ++e){
			int X = W.first+dir[e].first, Y = W.second+dir[e].second;
			if (X<0 || X >= n || Y < 0 || Y >= m || matrix[X][Y] == '.'){
				continue;
			}
			if (spec[X][Y] <= spec[W.first][W.second]+1) continue;
			spec[X][Y] = spec[W.first][W.second]+1;
			q.push({X, Y});
		}
	}

	for (int i=0;i<n;++i) for (int j=0;j<m;++j){
		if (matrix[i][j] != '.' && spec[i][j] > x) {
			//cout << "==== " << x << " " << i << " " << j << " " << spec[i][j] << endl;
			return false;
		}
	}

	return true;

}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<char> > matrix(n);
	vector<vector<bool> > used(n);
	vector<vector<int> > d(n);
	vector<vector<int> > spec(n);

	for (int i=0; i < n; ++i){
		for (int j=0; j < m; ++j){
			char ch;
			cin >> ch;
			matrix[i].push_back(ch);
			used[i].push_back(false);
			d[i].push_back(0);
			spec[i].push_back(0);
		}
	}

	queue<pair<int, int> > q;
	for (int i=0; i < n; ++i) for (int j=0; j < m; ++j){
		if (matrix[i][j] == '.') continue;
		bool nei = false;
		for (int e=0; e < 8; ++e){
			int X = i+dir[e].first, Y = j+dir[e].second;
			if (X<0 || X >= n || Y < 0 || Y >= m || matrix[X][Y] == '.'){
				nei = true;
			}
		}
		if (!nei) {
			d[i][j] = 1e9;
		}
		else q.push({i, j});
	}

	while (q.size()){
		pair<int, int> W = q.front();
		q.pop();
		for (int e=0; e < 8; ++e){
			int X = W.first+dir[e].first, Y = W.second+dir[e].second;
			if (X<0 || X >= n || Y < 0 || Y >= m || matrix[X][Y] == '.'){
				continue;
			}
			if (d[X][Y] <= d[W.first][W.second]+1) continue;
			d[X][Y] = d[W.first][W.second]+1;
			q.push({X, Y});
		}
	}
	
	int L = 0, R = max(n, m) + 1;
	while (R-L>1){
		int M = (L+R)/2;
		if (check(d, matrix, M, spec)) L = M;
		else R = M;
	}

	cout << L << endl;

	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (matrix[i][j] == '.') cout << '.';
			else if (d[i][j] >= L) cout << 'X';
			else cout << '.';
		}
		cout << "\n";
	}


	

}