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
bool ans[maxn];
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
    int l, r;
    if (n % 4 == 0)
        l = n / 2 - 1, r = n / 2;
    else
        l = r = (n + 1) / 2 - 1;
    if (l == r)
        ans[l] = 1, -- l, ++ r;
    for (; l >= 0 && r < n; l -= 2, r += 2){
        bool flag = false;
        for (int x = 0; x <= 1 && ! flag; ++ x)
            for (int y = 0; y <= 1 && ! flag; ++ y)
                if (s[l - x] == s[r + y])
                    ans[l - x] = ans[r + y] = true, flag = true;
    }
    for (int i = 0; i < n; ++ i)
        if (ans[i])
            putchar(s[i]);
}