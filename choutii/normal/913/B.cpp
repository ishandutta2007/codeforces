#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

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
const int N = 1234;

int n, p[N], nf[N], ch[N];
int main() {
	int i;
	cin >> n; 
	for(i = 2; i <= n; i++) {
		cin >> p[i];
		nf[p[i]]++;
	}
	for(i = 1; i <= n; i++) if(!nf[i]) ch[p[i]]++;
	int ok = 1;
	for(i = 1; i <= n; i++) if(nf[i] && ch[i] < 3) ok = 0; 
	if(ok) puts("Yes"); else puts("No");
	return 0;
}