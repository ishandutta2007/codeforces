#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vi V(n,0);
	vi F(n,-1);
	int cont = 0;
	vi S(k);
	for (int i = 0; i < k; ++i) {
		cin >> S[i];
		--S[i];
		if (F[S[i]] == -1) F[S[i]] = i;
	}
	int res = 0;
	for (int i = k-1; i >= 0; --i) {
		if (F[S[i]] == i) {
			if (S[i] > 0 and !V[S[i]-1]) ++res;
			if (S[i] < n-1  and !V[S[i]+1]) ++res;
		}
		V[S[i]] = 1;
	}
	for (int i = 0; i < n; ++i) {
		if (!V[i]) {
			if (i > 0) ++res;
			if (i < n-1) ++res;
			++res;
		}
	}
	cout << res << endl;
}