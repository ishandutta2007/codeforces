#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
#pragma warning(disable: 4996)
int n, a[300009], p[300009], q[300009]; vector<int>V; bool used[300009], used2[300009];
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { scanf("%d", &a[i]); p[a[i]]++; }
	for (int i = 1; i <= n; i++) { if (p[i] == 0) { V.push_back(i); } if (p[i] >= 1) used[i] = true; q[i] = p[i]; }
	sort(V.begin(), V.end());
	int c = 1;
	for (int i = 1; i <= n; i++) {
		if (p[a[i]] == 1)continue;
		while (used[c] == true)c++;
		q[a[i]]--;
		if (((q[a[i]] == 0 || c > a[i]) && used2[a[i]] == false)) {
			used[a[i]] = true; used2[a[i]] = true;
		}
		else { used[c] = true; used2[c] = true; a[i] = c; }
	}
	cout << V.size() << endl;
	for (int i = 1; i <= n; i++) { if (i >= 2)printf(" "); printf("%d", a[i]); }cout << endl;
	return 0;
}