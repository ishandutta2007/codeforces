/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int p[N], a[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		p[i] = -1;
	for (int i = 0; i < n; i++) {
		cout << "? ";
		for (int j = 0; j < n; j++) {
			if (i == j) 
				cout << "2 ";
			else
				cout << "1 ";
		}
		cout << endl;
		int k;
		cin >> k;
		k--;
		if (k != i && k != -1) {
			p[k] = i;
		}
		cout << "? ";
		for (int j = 0; j < n; j++) {
			if (i == j) 
				cout << "1 ";
			else
				cout << "2 ";
		}
		cout << endl;
		cin >> k;
		k--;
		if (k != i && k != -1) {
			p[i] = k;
		}
	}
	for (int i = 0; i < n; i++) {
		if (p[i] == -1)
			a[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[j] != -1 && a[p[j]] == i - 1) {
				a[j] = i;
			}
		}
	}
	cout << "! ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}