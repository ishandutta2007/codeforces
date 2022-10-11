#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;
#pragma warning(disable:4996)
int k, n, a[300009], ret[300009], cx; bool c[600009]; vector<pair<int, int>>Z;
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); Z.push_back(make_pair(a[i], i)); }
	sort(Z.begin(), Z.end(), greater<pair<int, int>>());
	cx = k + 1; long long B = 0;
	for (int i = 0; i < Z.size(); i++) {
		int to = Z[i].second;
		if (cx <= to) { c[to] = true; ret[to] = to; }
		else { while (c[cx] == true) { cx++; } c[cx] = true; ret[to] = cx; B += 1LL * a[to] * (cx - to); cx++; }
	}
	cout << B << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2)printf(" "); printf("%d", ret[i]); }cout << endl;
	return 0;
}