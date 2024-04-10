#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

int N;
int X[100100];
int m[100100], M[100100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for(int n = 0; n < N; ++n) cin >> X[n];
	for(int n = 0; n < N; ++n) {
		m[n] = (1 << 31) - 1;
		if(n > 0) m[n] = min(m[n], X[n] - X[n - 1]);
		if(n < N - 1) m[n] = min(m[n], X[n + 1] - X[n]);
		M[n] = 0;
		if(n > 0) M[n] = max(M[n], X[n] - X[0]);
		if(n < N - 1) M[n] = max(M[n], X[N - 1] - X[n]);
	}
	
	for(int n = 0; n < N; ++n) cout << m[n] << ' ' << M[n] << '\n';
}