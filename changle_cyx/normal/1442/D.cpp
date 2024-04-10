#include <bits/stdc++.h>

using namespace std; 

typedef long long s64; 

template <class T>
inline void read(T &x) {
	static char ch; 
	while (!isdigit(ch = getchar())); 
	x = ch - '0'; 
	while (isdigit(ch = getchar()))
		x = x * 10 + ch - '0'; 
}

template <class T>
inline void relax(T &x, const T &y) {
	if (x < y) x = y; 
}

const int MaxN = 3000 + 5; 
const int MaxK = 3000 + 5; 
const int MaxT = 1000000 + 5; 

int n, K, len[MaxN]; 

s64 ans; 
vector<s64> s[MaxN]; 

s64 f[MaxN]; 

void solve(int l, int r) {
	if (l > r) return; 
	if (l == r) {
		for (int i = 0; i <= len[l] && i <= K; ++i)
			relax(ans, s[l][i] + f[K - i]); 
		return;  
	}

	int mid = (l + r) >> 1; 
	vector<s64> tf(f, f + K + 1); 

	for (int i = l; i <= mid; ++i)
		for (int j = K; j >= len[i]; --j) relax(f[j], f[j - len[i]] + s[i].back()); 
	solve(mid + 1, r); 
	
	for (int j = 0; j <= K; ++j) f[j] = tf[j]; 
	for (int i = mid + 1; i <= r; ++i)
		for (int j = K; j >= len[i]; --j) relax(f[j], f[j - len[i]] + s[i].back()); 
	solve(l, mid); 

	for (int j = 0; j <= K; ++j) f[j] = tf[j]; 
}
//
int main() {
	read(n), read(K); 
	for (int i = 1; i <= n; ++i) {
		read(len[i]); 

		s[i] = vector<s64>(len[i] + 1); 
		for (int j = 1, x; j <= len[i]; ++j) {
			read(x), s[i][j] = s[i][j - 1] + x; 
		}
	}

	solve(1, n); 
	cout << ans << '\n'; 
	
	return 0; 
}