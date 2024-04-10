#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int N;
ll x1, y1, x2, y2;
ll A[300], B[300], C[300];
int ans = 0;

int sgn(ll x) {
	return (x > 0) ? (1) : (-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> N;
	for(int n = 0; n < N; ++n)
		cin >> A[n] >> B[n] >> C[n];
		
	for(int n = 0; n < N; ++n) {
		if(sgn(A[n] * x1 + B[n] * y1 + C[n]) * sgn(A[n] * x2 + B[n] * y2 + C[n]) < 0) ++ans;
	}
	
	cout << ans;
}