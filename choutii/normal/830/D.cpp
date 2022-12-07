#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int P = 1e9 + 7, MaxN = 405;

int h, f[MaxN][MaxN];

int main() {
	h = read();
	f[1][0] = f[1][1] = 1;
	for (int i = 2; i <= h; i++) 
		for (int l = 0; l <= h; l++)
			for (int r = 0; l + r - 1 <= h; r++) {
				int inc = (LL) f[i - 1][l] * f[i - 1][r] % P;
				(f[i][l + r + 1] += inc) %= P;	
				(f[i][l + r] += (LL) inc * (2 * l + 2 * r + 1) % P) %= P;
				if(l || r) 
					(f[i][l + r - 1] += (LL) inc * (l + r) % P * (l + r - 1) % P) %= P; 
			}
		
	cout << f[h][1] << endl;
	return 0;
}