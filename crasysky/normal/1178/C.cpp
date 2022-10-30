#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int P = 998244353;
const int maxn = 2000006;
const int INF = 1000000000;
int a[maxn], sl[maxn], sr[maxn];
int read(){
	int c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int n = read(), m = read();
    int ans = 4;
    for (int i = 1; i < n; ++ i)
        ans = 2LL * ans % P;
    for (int i = 1; i < m; ++ i)
        ans = 2LL * ans % P;
    cout << ans << endl;
}
/*
100
30 99 96 51 67 72 33 35 93 70 25 24 6 9 22 83 86 5 79 46 29 88 66 20 87 47 45 71 48 52 61 37 19 40 44 11 8 42 63 92 31 94 2 4 28 77 21 75 13 95 76 14 53 69 54 38 59 60 98 55 39 68 85 23 15 18 58 78 43 49 16 1 82 91 7 84 34 89 17 27 90 26 36 81 64 74 50 57 10 73 12 62 3 100 80 32 56 41 97 65
*/