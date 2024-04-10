#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#define Pr pair <int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
const int P = 1e9 + 7;
int p[maxn], x, a, y, b;
long long k;
bool check(int n){
    int c = 0, c1 = 0, c2 = 0;
    for (int i = 1; i <= n; ++ i)
        if (i % a == 0 && i % b == 0)
            ++ c;
        else if (i % a == 0)
            ++ c1;
        else if (i % b == 0)
            ++ c2;
    long long s = 0;
    for (int i = 1; i <= n; ++ i){
        if (c)
            s += 1LL * p[i] * (x + y), -- c;
        else if (c1)
            s += 1LL * p[i] * x, -- c1;
        else if (c2)
            s += 1LL * p[i] * y, -- c2;
        else
            break;
    }
    return s >= k;
}
long long read(){
	long long c = 0, f = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
	return c * f;
}
int main(){
    int q = read();
    while (q --){
        int n = read();
        for (int i = 1; i <= n; ++ i)
            p[i] = -read() / 100;
        sort(p + 1, p + 1 + n);
        for (int i = 1; i <= n; ++ i)
            p[i] = -p[i];
        x = read(), a = read(), y = read(), b = read(), k = read();
        if (x < y)
            swap(x, y), swap(a, b);
        int l = 1, r = n, ans = -1;
        while (l <= r){
            int m = l + r >> 1;
            if (check(m))
                ans = m, r = m - 1;
            else
                l = m + 1;
        }
        cout << ans << endl;
    }
}