/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202, M = 1024;
int a[N], b[N];
int f[M];

int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < M; i++)
		f[i] = 1;
	for (int i = 0; i < n; i++) {
		vector <int> v;
		for (int j = 0; j < M; j++) {
			if (f[j] == 1) {
				v.push_back(j);
			}
			f[j] = 0;
		}
		for (int j = 0; j < m; j++) {
            for (int k = 0; k < (int)v.size(); k++) {
                f[((a[i] & b[j]) | v[k])] = 1;
            }
        }
	}
	int ans = -1;
	for (int i = 0; i < M; i++) {
		if (f[i]) {
			ans = i;
			break;
		}
	}
	cout << ans;
}