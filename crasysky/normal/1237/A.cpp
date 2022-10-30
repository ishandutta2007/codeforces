#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const long long INF = 1LL << 60;
const int maxn = 1e6 + 6;
int a[maxn];
bool tag[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), c1 = 0, c2 = 0;
    for (int i = 1; i <= n; ++ i){
        a[i] = read();
        if (a[i] % 2)
            tag[i] = true;
    }
    for (int i = 1; i <= n; ++ i)
        if (a[i] > 0)
            a[i] = (a[i] + 1) / 2;
        else
            a[i] = a[i] / 2;
    int s = 0;
    for (int i = 1; i <= n; ++ i)
        s += a[i];
    for (int i = 1; i <= n; ++ i)
        if (tag[i] && s)
            -- a[i], -- s;
    for (int i = 1; i <= n; ++ i)
        cout << a[i] << endl;
}