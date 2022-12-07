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

const int MaxN = 1001234;

int n, t1[MaxN], t0[MaxN], x[MaxN]; 
char op[MaxN];	

void move(int &x, int y, char c) {
	if(c == '|') x |= y;
	if(c == '^') x ^= y;
	if(c == '&') x &= y;
}

vector<int> f[2][2];
int main() {
	int i, j;
	n = read();
	for(i = 1; i <= n; i++) {
		char t[5]; scanf("%s", t);
		op[i] = t[0];
		x[i] = read();
	}
	for(i = 0; i < 10; i++) {
		t1[i] = 1;
		for(j = 1; j <= n; j++)
			move(t1[i], x[j] >> i & 1, op[j]);
		for(j = 1; j <= n; j++)
			move(t0[i], x[j] >> i & 1, op[j]);
	}
	
	for(i = 0; i < 10; i++) {
		f[t0[i]][t1[i]].push_back(i); 
	}
	
	puts("3");
	
	int x = 0;
	for(i = 0; i < f[1][0].size(); i++) 
		x ^= (1 << f[1][0][i]);
	
	printf("^ %d\n", x);
	
	x = 0;
	for(i = 0; i < f[1][1].size(); i++) 
		x ^= (1 << f[1][1][i]);
	printf("| %d\n", x);
	
	x = 1023;
	for(i = 0; i < f[0][0].size(); i++)
		x ^= (1 << f[0][0][i]);
	printf("& %d\n", x);
	return 0;
}