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
int n, m; char s[66][66], t[233];

pair<int, int> d[4]; int p[4];

bool chk() {
	int i, j, sx, sy;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++) {
			if(s[i][j] == 'S') sx = i, sy = j;
		}
	int tn = strlen(t + 1);
	for(i = 1; i <= tn; i++) {
		sx += d[p[t[i] - '0']].fir;
		sy += d[p[t[i] - '0']].sec;
		if(sx < 1 || sy < 1 || sx > n || sy > m) return 0;
		if(s[sx][sy] == '#') return 0; 
		if(s[sx][sy] == 'E') return 1;
	} 
	return 0;
} 

int main() {
	int i, j;
	n = read(); m = read();
	d[0] = MP(0, -1);
	d[1] = MP(0, 1);
	d[2] = MP(1, 0);
	d[3] = MP(-1, 0);
	for(i = 0; i < 4; i++) p[i] = i;
	for(i = 1; i <= n; i++) 
		scanf("%s" , s[i] + 1);
	scanf("%s", t + 1);
	int ans = 0;
	do {
		ans += chk();
	}while(next_permutation(p, p + 4));cout << ans;
	return 0;
}