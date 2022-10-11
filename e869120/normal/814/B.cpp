#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include<queue>
using namespace std;
int n, a[100000], b[100000], c[100000], d[100000];
bool isperm() {
	for (int i = 1; i <= n; i++)d[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (d[c[i]] >= 1)return false;
		d[c[i]] = 1;
	}
	return true;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	vector<int>B;
	for (int i = 1; i <= n; i++) { if (a[i] != b[i])B.push_back(i); }
	if (B.size() == 0) {
		for (int i = 1; i <= n; i++)d[a[i]]++;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[i] == a[j]) {
					int G = 0; for (int k = 1; k <= n; k++) { if (d[k] == 0)G = k; }
					a[i] = G;
					for (int k = 1; k <= n; k++) { if (k >= 2)cout << ' '; cout << a[k]; }cout << endl;
					return 0;
				}
			}
		}
	}
	if (B.size() == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)c[j] = a[j];
			c[B[0]] = i;
			if (isperm() == true) { for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << c[i]; } cout << endl; return 0; }
		}
	}
	if (B.size() == 2) {
		for (int i = 1; i <= n; i++)c[i] = a[i];
		c[B[1]] = b[B[1]];
		if (isperm() == true) { for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << c[i]; } cout << endl; return 0; }
		for (int i = 1; i <= n; i++)c[i] = a[i];
		c[B[0]] = b[B[0]];
		if (isperm() == true) { for (int i = 1; i <= n; i++) { if (i >= 2)cout << ' '; cout << c[i]; } cout << endl; return 0; }
	}
	return 0;
}