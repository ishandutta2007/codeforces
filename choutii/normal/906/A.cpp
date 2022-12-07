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

const int MaxN = 101234;
int n, a[27], b[27]; char s[MaxN], op[MaxN];

int check() {
	int j = 0;
	for(int i = 0; i < 26; i++) {
		if(b[i] == 1) return 1; j += !b[i];
	}
	return j == 25;
}
int main() {
	int i, j; memset(b, -1, sizeof(b));
	n = read(); bool chk = 0;  int ans = 0;
	for(i = 1; i <= n; i++) {
		scanf("%s%s", op, s);
		if(*op == '!') {
			memset(a, 0, sizeof(a));
			for(j = 0; s[j]; j++)
				a[s[j] - 'a'] = 1;
			for(j = 0; j < 26; j++) if(!a[j]) b[j] = 0;	
			ans += chk;
		}
		if(*op == '.') {
			for(j = 0; s[j]; j++) b[s[j] - 'a'] = 0;
		}
		if(*op == '?') {
			if(i == n) 
				b[s[0] - 'a'] = 1;
			else
				ans += chk, b[s[0] - 'a'] = 0;
		}
		if(check()) chk = 1;
	}
	cout << ans << endl;
	return 0;
}