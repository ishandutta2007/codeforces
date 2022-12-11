#include<bits/stdc++.h>

using namespace std;

const int N = 5010;

typedef long long ll;

ll D[N][N];
ll A[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> A[i];
	for (int i = 0; i < n; ++i) {
		D[i][i] = A[i];
		int l = 0;
		int k = 1;
		int cont = 0;
		for (int j = i-1; j >= 0; --j) {
			D[j][i] = D[j][i-k]^D[i-l][i];
			++cont;
			++l;
			if (k == cont) {
			       k *= 2;
			       cont = 0;
			       l = 0;
			}
		}		
	}
	for (int i = 0; i < n; ++i) {
		ll ma = 0;
		for (int j = i; j < n; ++j) {
			ma = max(ma, D[i][j]);
			D[i][j] = ma;
		}
	}
	for (int i = 0; i < n; ++i) {
		ll ma = 0;
		for (int j = i; j >= 0; --j) {
			ma = max(ma, D[j][i]);
			D[j][i] = ma;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x,y;
		cin >> x >>y;
		--x; --y;
		cout << D[x][y]<< '\n';
	}
}