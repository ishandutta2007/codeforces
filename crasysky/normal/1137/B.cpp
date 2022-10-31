#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int INF = 1e9;
const int b1 = 23;
const int b2 = 37;
const int P1 = 1e9 + 7;
const int P2 = 998244353;
const int maxn = 1000006;
int pw[maxn][2], sl[maxn][2], sr[maxn][2];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f; 
} 
int main(){
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	sl[0][0] = sl[0][1] = t[0] - '0';
	for (int i = 1; i < m; ++ i){
		sl[i][0] = (1LL * sl[i - 1][0] * b1 + t[i] - '0') % P1;
		sl[i][1] = (1LL * sl[i - 1][1] * b2 + t[i] - '0') % P2;
	}
	pw[0][0] = pw[0][1] = 1;
	for (int i = 1; i <= m; ++ i){
		pw[i][0] = 1LL * pw[i - 1][0] * b1 % P1;
		pw[i][1] = 1LL * pw[i - 1][1] * b2 % P2;
	}
	sr[m - 1][0] = sr[m - 1][1] = t[m - 1] - '0';
	for (int i = m - 2; i >= 0; -- i){
		sr[i][0] = (sr[i + 1][0] + 1LL * (t[i] - '0') * pw[m - 1 - i][0]) % P1;
		sr[i][1] = (sr[i + 1][1] + 1LL * (t[i] - '0') * pw[m - 1 - i][1]) % P2;
	}
	int mx = 0;
	for (int i = m - 1; i; -- i)
		if (sl[i - 1][0] == sr[m - i][0] && sl[i - 1][1] == sr[m - i][1]){
			mx = i;
			break;
		}
	int c0 = 0, c1 = 0;
	for (int i = mx; i < m; ++ i){
		c0 += t[i] - '0' == 0;
		c1 += t[i] - '0' == 1;
	}
	int t0 = 0, t1 = 0;
	for (int i = 0; i < m; ++ i){
		t0 += t[i] - '0' == 0;
		t1 += t[i] - '0' == 1;
	}
	int s0 = 0, s1 = 0;
	for (int i = 0; i < n; ++ i){
		s0 += s[i] - '0' == 0;
		s1 += s[i] - '0' == 1;
	}
	if (s0 < t0 || s1 < t1){
		cout << s << endl;
		return 0;
	}
	s0 -= t0, s1 -= t1;
	int c = min(c0 ? s0 / c0 : INF, c1 ? s1 / c1 : INF);
	s0 -= c * c0, s1 -= c * c1;
	for (int i = 0; i < m; ++ i)
		putchar(t[i]);
	for (int j = 1; j <= c; ++ j)
		for (int i = mx; i < m; ++ i)
			putchar(t[i]);
	for (int i = 0; i < s0; ++ i)
		putchar('0');
	for (int i = 0; i < s1; ++ i)
		putchar('1');
	return 0;
}
/*
1010101010
111
*/