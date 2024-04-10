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

int grand(int n) {
	return (LL) rand() * rand() % n + 1;
}

int n, st, x, a = -1, b;
 
int main() {
	int i;
	srand(20171025);
	n = read(); st = read(); x = read();
	b = st;
	for(i = 1; i <= 1000; i++) {
		cout << "? " << grand(n) << endl; 
		fflush(stdout);
		int val = read(), nxt = read();
		if(val < x) 
			if(cmax(a, val))
				a = val, b = nxt;
	}
	
	while(a < x) {
		if(b < 0) return puts("! -1"), 0;
		cout << "? " << b << endl;
		fflush(stdout);
		a = read(); b = read();
	}
	printf("! %d\n", a);
	return 0;
}