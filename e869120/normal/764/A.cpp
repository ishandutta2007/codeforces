#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int n, m, p, a[100000];
int main() {
	cin >> n >> m >> p;
	for (int i = n; i <= p; i += n)a[i]++;
	for (int i = m; i <= p; i += m)a[i]++;
	int cnt = 0;
	for (int i = 1; i <= p; i++) { if (a[i] >= 2)cnt++; }
	cout << cnt << endl;
	return 0;
}