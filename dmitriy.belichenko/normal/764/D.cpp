#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
#include<set>
#include<map>
#include<time.h>
#include<cmath>
#include<queue>
#define li long long
#define mp make_pair

using namespace std;



int main() {
	//freopen("subgraph.in", "r", stdin);
	//freopen("subgraph.out", "w", stdout);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(4));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> a[i][j];
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << 1 + (min(a[i][0], a[i][2]) % 2 + 2) % 2 + 2 * ((min(a[i][1], a[i][3]) % 2 + 2) % 2) << endl;
	}
}