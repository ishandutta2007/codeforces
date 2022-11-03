#include <bits/stdc++.h>

using namespace std;

int N;
char S[100100], T[100100];

int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> S >> T;
	int L = 0;
	while(S[L] == T[L])
		++L;
	int R = N - 1;
	while(S[R] == T[R])
		--R;
	cout << int(equal(S + L + 1, S + R + 1, T + L)) + int(equal(S + L, S + R, T + L + 1)) << '\n';
}