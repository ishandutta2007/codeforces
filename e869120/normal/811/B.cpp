#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int n, m, a[100000], p[100000];
int main() {
	cin >> n >> m; for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 0; i < m; i++) {
		int a1, b, c; cin >> a1 >> b >> c;
		for (int j = 0; j < 12000; j++)p[j] = 0;
		for (int j = a1; j <= b; j++)p[a[j]]++;
		for (int j = 1; j < 12000; j++)p[j] += p[j - 1];
		if (p[a[c]] == c - a1 + 1)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}