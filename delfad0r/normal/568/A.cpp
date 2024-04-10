#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000000;
int P[MAXN], R[MAXN];

void fillP() {
	for(int p = 2; p < MAXN; ++p) P[p] = 1;
	for(int p = 2; p < MAXN; ++p) {
		if(!P[p]) continue;
		if(p > sqrt(MAXN)) continue;
		for(int i = p * p; i < MAXN; i += p)
			P[i] = false;
	}
	for(int p = 1; p < MAXN; ++p) P[p] += P[p - 1];
}

void fillR() {
	char d[10];
	for(int n = 1; n < MAXN; ++n) {
		int N = n;
		int c = 0;
		while(N) {
			d[c++] = N % 10;
			N /= 10;
		}
		bool ok = true;
		for(int i = 0; ok && i < c / 2; ++i)
			if(d[i] != d[c - 1 - i]) ok = false;
		R[n] = ok;
		if(n > 0) R[n] += R[n - 1];
	}
}

long long A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> A >> B;
	
	fillP();
	fillR();
	
	int ans = -1;
	for(int n = 0; n < MAXN; ++n)
		if(B * P[n] <= A * R[n]) ans = n;
	if(ans == -1) cout << "Palindromic tree is better than splay tree";
	else cout << ans;
}