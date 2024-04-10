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
const int maxn = 3000006;
int m, ans[maxn][2], a[maxn], p[maxn];
void S(int x, int y){
    ans[++ m][0] = x, ans[m][1] = y;
    swap(a[x], a[y]);
    p[a[x]] = x, p[a[y]] = y;
}
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        p[a[i] = read()] = i;
    if (p[1] != 1){
        if (p[1] <= n / 2)
            S(p[1], n), S(n, 1);
        else
            S(p[1], 1);
    }
    for (int i = 2; i <= n / 2; ++ i)
        if (p[i] != i){
            if (p[i] <= n / 2)
                S(p[i], n), S(n, i);
            else{
                if (p[i] != n){
                    int x = p[i];
                    S(p[i], 1), S(1, n), S(n, i), S(x, 1);
                }
                else
                    S(p[i], i);
            }
        }
    for (int i = n / 2 + 1; i <= n; ++ i)
        if (p[i] != i){
            int x = p[i];
            S(p[i], 1), S(1, i), S(x, 1);
        }
    cout << m << endl;
    for (int i = 1; i <= m; ++ i)
        printf("%d %d\n", ans[i][0], ans[i][1]);
}