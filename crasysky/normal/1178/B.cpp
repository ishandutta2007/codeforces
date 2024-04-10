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
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; ++ i)
        a[i] = s[i - 1] == 'v';
    for (int i = 1; i <= n; ++ i)
        sl[i] = sl[i - 1] + (a[i] && a[i - 1]);
    for (int i = n; i; -- i)
        sr[i] = sr[i + 1] + (a[i] && a[i + 1]);
    long long ans = 0;
    for (int i = 1; i <= n; ++ i)
        if (a[i] == 0)
            ans += 1LL * sl[i - 1] * sr[i + 1];
    cout << ans << endl;
}