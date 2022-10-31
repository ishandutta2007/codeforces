#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1005;
ll a[N][N];
ll b[N], n;

void go(ll v) {
	b[0] = v;
	for(int i = 1; i < n; ++i) {
		b[i] = a[0][i] / b[0];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i+1; j < n; ++j) {
			if(b[i]*b[j] != a[i][j])
				return;
		}
	}
	for(int i = 0; i < n; ++i)
		cout << b[i] << ' ';
	cout << '\n';
	exit(0);
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	for(ll i = 1; i*i <= a[0][1]; ++i) {
		if(a[0][1] % i == 0) {
			go(i);
			go(a[0][1]/i);
		}
	}
}