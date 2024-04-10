#include <bits/stdc++.h>

using namespace std;

int N;
char S[2][1000100];
char U[2000100];
int Z[2000100];

void Zalgo() {
	int l = 0, r = 0;
	for(int i = 1; i < N; ++i) {
		if(i <= r)
			Z[i] = min(Z[i - l], r - i + 1);
		while(i + Z[i] < N && U[i + Z[i]] == U[Z[i]])
			++Z[i];
		if(i + Z[i] - 1 > r)
			l = i, r = i + Z[i] - 1;
	}
};

char inv(const char c) {
	if(c == 'N') return 'S';
	if(c == 'S') return 'N';
	if(c == 'W') return 'E';
	if(c == 'E') return 'W';
	abort();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	cin >> S[0] >> S[1];
	--N;
	reverse(S[0], S[0] + N);
	for(int n = 0; n < N; ++n)
		U[n] = inv(S[0][n]);
	memcpy(U + N, S[1], N);
	N *= 2;
	Zalgo();
	N /= 2;
	for(int n = N; n < 2 * N; ++n) {
		if(Z[n] + n >= 2 * N) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}