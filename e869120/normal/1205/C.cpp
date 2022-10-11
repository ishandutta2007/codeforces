#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

int N, col[59][59];
vector<tuple<int, int, int>> G[59][59];

void dfs(int px, int py, int dep) {
	col[px][py] = dep;
	for (tuple<int, int, int> i : G[px][py]) {
		if (col[get<0>(i)][get<1>(i)] != -1) continue;
		dfs(get<0>(i), get<1>(i), dep ^ get<2>(i));
	}
}

int main() {
	cin >> N;

	//  1.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - 2; j++) {
			cout << "? " << i << " " << j << " " << i << " " << j + 2 << endl;
			int v; cin >> v;
			G[i][j].push_back(make_tuple(i, j + 2, 1 - v));
			G[i][j + 2].push_back(make_tuple(i, j, 1 - v));
		}
	}

	//  2.
	for (int i = 1; i <= N - 2; i++) {
		for (int j = 1; j <= 2; j++) {
			cout << "? " << i << " " << j << " " << i + 2 << " " << j << endl;
			int v; cin >> v;
			G[i][j].push_back(make_tuple(i + 2, j, 1 - v));
			G[i + 2][j].push_back(make_tuple(i, j, 1 - v));
		}
	}

	//  3.
	cout << "? 1 1 2 2" << endl;
	int v1; cin >> v1;
	G[1][1].push_back(make_tuple(2, 2, 1 - v1));
	G[2][2].push_back(make_tuple(1, 1, 1 - v1));

	//  4.
	cout << "? 1 2 2 3" << endl;
	int v2; cin >> v2;
	G[1][2].push_back(make_tuple(2, 3, 1 - v2));
	G[2][3].push_back(make_tuple(1, 2, 1 - v2));

	//  5. 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) col[i][j] = -1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (col[i][j] != -1) continue;
			dfs(i, j, 1);
		}
	}

	//  5. 
	int hosei = -1;
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if ((i + j) % 2 == 1) continue;
			if (col[i][j + 1] != col[i + 1][j]) {
				if (j != 1) {
					cout << "? " << i << " " << j - 1 << " " << i + 1 << " " << j + 1 << endl;
					int va; cin >> va; va = (1 - va);
					int vb = (col[i][j - 1] ^ col[i + 1][j + 1]);
					hosei = (va ^ vb);
					break;
				}
				if (j != N - 1) {
					cout << "? " << i << " " << j << " " << i + 1 << " " << j + 2 << endl;
					int va; cin >> va; va = (1 - va);
					int vb = (col[i][j] ^ col[i + 1][j + 2]);
					hosei = (va ^ vb);
					break;
				}
			}
		}
		if (hosei != -1) break;
	}

	if (hosei == -1) {
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= N - 1; j++) {
				if ((i + j) % 2 == 1) continue;
				if (col[i][j] == col[i + 1][j + 1]) {
					if (j != 1 && col[i + 1][j - 1] == col[i + 1][j + 1]) {
						cout << "? " << i << " " << j - 1 << " " << i + 1 << " " << j + 1 << endl;
						int va; cin >> va; va = (1 - va);
						int vb = (col[i][j - 1] ^ col[i + 1][j + 1]);
						hosei = (va ^ vb);
						break;
					}
					if (j != N - 1 && col[i + 1][j] == col[i + 1][j + 2]) {
						cout << "? " << i << " " << j << " " << i + 1 << " " << j + 2 << endl;
						int va; cin >> va; va = (1 - va);
						int vb = (col[i][j] ^ col[i + 1][j + 2]);
						hosei = (va ^ vb);
						break;
					}
				}
			}
			if (hosei != -1) break;
		}
	}

	if (hosei == -1) {
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 1; j <= N - 1; j++) {
				if ((i + j) % 2 == 1) continue;
				if (col[i][j] != col[i + 1][j + 1]) {
					if (j != 1 && col[i + 1][j - 1] != col[i + 1][j + 1]) {
						cout << "? " << i << " " << j - 1 << " " << i + 1 << " " << j + 1 << endl;
						int va; cin >> va; va = (1 - va);
						int vb = (col[i][j - 1] ^ col[i + 1][j + 1]);
						hosei = (va ^ vb);
						break;
					}
					if (j != N - 1 && col[i + 1][j] != col[i + 1][j + 2]) {
						cout << "? " << i << " " << j << " " << i + 1 << " " << j + 2 << endl;
						int va; cin >> va; va = (1 - va);
						int vb = (col[i][j] ^ col[i + 1][j + 2]);
						hosei = (va ^ vb);
						break;
					}
				}
			}
			if (hosei != -1) break;
		}
	}

	// 
	cout << "!" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if ((i + j) % 2 == 0) cout << col[i][j];
			else cout << (col[i][j] ^ hosei);
		}
		cout << endl;
	}
	return 0;
}