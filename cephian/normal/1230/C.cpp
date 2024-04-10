#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 279936;
bool used[6][6] = {};
int lab[7], a[49], b[49];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i];
		--a[i], --b[i];
	}
	int ans = 0;
	for(int i = 0; i < MAX; ++i) {
		int tmp = i;
		for(int j = 0; j < n; ++j) {
			lab[j] = tmp%6;
			tmp /= 6;
		}
		for(int j = 0; j < m; ++j) {
			int A = lab[a[j]];
			int B = lab[b[j]];
			if(A < B) swap(A, B);
			used[A][B] = true;
		}
		int cov = 0;
		for(int j = 0; j < 6; ++j)
			for(int k = 0; k <= j; ++k) {
				cov += used[j][k];
				used[j][k] = false;
			}
		ans = max(cov, ans);
	}
	cout << ans << '\n';
}