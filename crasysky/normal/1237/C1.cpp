#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const long long INF = 1e9;
const int maxn = 1e6 + 6;
int x[maxn], y[maxn], z[maxn];
bool del[maxn];
int aabs(int x){
    return x >= 0 ? x : -x;
}
int d(int x1, int y1, int z1, int x2, int y2, int z2){
    return aabs(x1 - x2) + aabs(y1 - y2) + aabs(z1 - z2);
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
    for (int i= 1; i <= n; ++ i)
        x[i] = read(), y[i] = read(), z[i] = read();
    for (int i = 1; i <= n; ++ i){
        if (del[i])
            continue;
        int mn, mnd = INF;
        for (int j = 1; j <= n; ++ j){
            int _d = d(x[i], y[i], z[i], x[j], y[j], z[j]);
            if (i != j && ! del[j] && _d < mnd){
                mn = j, mnd = _d;
            }
        }
        cout << i << " " << mn << endl;
        del[i] = del[mn] = true;
    }
}