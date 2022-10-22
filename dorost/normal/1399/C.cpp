/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 51;
int a[N];
bool mark[N];

int32_t main(){
	int t;
	cin >> t;
	while (t--) { 
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> a[i];
		int x = 0;
		for (int s = 2; s <= 100; s++) {
			int ans = 0;
			for (int i = 0; i < N; i++)
				mark[i] = false;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (mark[i] || mark[j] || i >= j)
						continue;
					if (a[i] + a[j] == s) {
						mark[i] = true;
						mark[j] = true;
						ans++;
						break;
					}
				}
			}
			x = max(x, ans);
		}
		cout << x << endl;
	}
}