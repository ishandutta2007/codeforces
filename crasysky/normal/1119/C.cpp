#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 1003;
int a[maxn][maxn], b[maxn][maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), m = read();
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            a[i][j] = read();
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            b[i][j] = read();
    for (int i = 1; i < n; ++ i)
        for (int j = 1; j < m; ++ j)
            if (a[i][j] != b[i][j])
                a[i][j] ^= 1, a[i + 1][j] ^= 1, a[i][j + 1] ^= 1, a[i + 1][j + 1] ^= 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            if (a[i][j] != b[i][j]){
                cout << "No" << endl;
                return 0;
            }
    cout << "Yes" << endl;
}