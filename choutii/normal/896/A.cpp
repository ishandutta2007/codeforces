#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

string A = "What are you doing at the end of the world? Are you busy? Will you save us?";
string B[3] = {
"What are you doing while sending \"",
"\"? Are you busy? Will you send \"",
"\"?"
};

LL len[123456];
char solve(int n, LL K) {
	if(K >= len[n]) return '.';
	if(n == 0) return A[K];
	for(int i = 0; i < 3; i++) {
		if(K < B[i].size()) return B[i][K];
		if((K -= B[i].size()) < len[n - 1]) return solve(n - 1, K);
		K -= len[n - 1]; 
	}
}

int main() {
	int T, n; LL K; 
	len[0] = A.size();
	for(T = 1; T < 123456; T++) len[T] = min((LL) 1e18, 2 * len[T - 1] + (LL) (B[0] + B[1] + B[2]).size());
	cin >> T;
	while(T--) {
		cin >> n >> K;
		cout << solve(n, K - 1);
	}	
	return 0;
}