#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
int n, a[210000];
int main() {
	cin >> n; for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	sort(a, a + n);
	int cnt = 0, maxn = 2099999999;
	for (int i = 0; i < n - 1; i++) {
		int H = a[i + 1] - a[i]; 
		if (H < maxn) { maxn = H; cnt = 1; }
		else if (maxn == H) { cnt++; }
	}
	cout << maxn << ' ' << cnt << endl;
	return 0;
}