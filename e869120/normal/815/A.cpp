#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, x[200][200], p[200], q[200]; vector<pair<int, int>>U;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x[i][j];
		}
	}
	for (int i = 0; i < 114514; i++)U.push_back(make_pair(-1, -1));
	int r = 0;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j < m; j++)q[j] = x[0][j] - i;
		for (int j = 0; j < n; j++)p[j] = x[j][0] - x[0][0] + i;
		bool OK = true;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (x[j][k] != p[j] + q[k])OK = false;
			}
		}
		for (int j = 0; j < n; j++) { if (p[j] < 0)OK = false; }
		for (int j = 0; j < m; j++) { if (q[j] < 0)OK = false; }
		if (OK == true) {
			vector<pair<int, int>>V; r = 1;
			int G = 0;
			for (int j = 0; j < n; j++)G += p[j];
			for (int j = 0; j < m; j++)G += q[j];
			for (int j = 0; j < n; j++) { for (int k = 0; k < p[j]; k++)V.push_back(make_pair(1, j)); }
			for (int j = 0; j < m; j++) { for (int k = 0; k < q[j]; k++)V.push_back(make_pair(2, j)); }
			if (V.size() < U.size())U = V;
		}
	}
	if (U.size() == 114514) { cout << "-1" << endl; }
	else {
		cout << U.size() << endl;
		for (int i = 0; i < U.size(); i++) {
			if (U[i].first == 1)printf("row %d\n", U[i].second + 1);
			if (U[i].first == 2)printf("col %d\n", U[i].second + 1);
		}
	}
	return 0;
}