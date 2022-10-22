/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
int cnt[N], x[N];
string s[N];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		cin >> s[i];
	int mx = 0;
	for (int l = 0; l < m; l++) {
		for (int i = 0; i < N; i++) 
			cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			int an = 0;
			if (l < x[i]) {
				an = x[i] - l + 1;
			} else {
				for (int j = l; j < m; j++) {
					if (s[i][j] == '0')
						break;
					x[i] = j;
					an++;
				}
			}
			cnt[an]++;
		}
		/*for (int i = 1; i <= 10; i++)
			cout << cnt[i] << ' ';
		cout << endl; */
		for (int i = N - 2; i >= 0; i--) {
			cnt[i] += cnt[i + 1];
		}
		for (int i = 0; i < N; i++)  {
			mx = max(mx, i * cnt[i]);
		}
	}
	cout << mx;
}