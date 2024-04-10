#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n;
bool matrix[2000][2000];
int deg[2000];
int ways[3];

bool check() {
	vector<int> degs;
	for (int i = 0; i < n; ++i) degs.push_back(deg[i]);
	sort(degs.begin(), degs.end());
	
	int sum = 0;
	for (int i = 0; i+1 < n; ++i) {
		sum += degs[i];
		if (sum == i*(i+1)/2) return false;
	}
	return true;

}

void revert(int x) {
	for (int i = 0; i < n; ++i) {
		if (i==x) continue;
		if (matrix[x][i]) {
			deg[x]--, deg[i]++;
			matrix[x][i] = false, matrix[i][x] = true;
		}
		else{
			deg[i]--, deg[x]++;
			matrix[x][i] = true, matrix[i][x] = false;
		}
	}
}

void recursion(int lvl) {
	if (check()) {
		ways[lvl]++;
		return;
	}
	if (lvl == 2) return;
	for (int i = 0; i < n; ++i) {
		revert(i);
		recursion(lvl+1);
		revert(i);
	}
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
		char ch;
		cin >> ch;
		if (ch == '1') {
			deg[i]++;
			matrix[i][j] = true;
		}
	}

	if (n <= 6) {
		recursion(0);
		for (int i = 0; i <= 2; ++i) {
			if (ways[i]) {
				cout << i << " " << ways[i];
				exit(0);
			}
		}
		cout << -1;
		exit(0);
	}

	if (check()) {
		cout << "0 1";
		return 0;
	}

	int cnt = 0;
	for (int i = 0;i<n;++i){
		revert(i);
		if (check()) cnt++;
		revert(i);
	}
	if (cnt == 0) {
		cout << -1;
	}
	else cout << 1 << " " << cnt;


}