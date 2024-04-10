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
const int maxn = 1000006;
int a[maxn], b[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), h = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= i; ++ j)
            b[j] = a[j];
        sort(b + 1, b + 1 + i);
        long long c = 0;
        for (int j = i; j >= 1; j -= 2)
            c += max(b[j], b[j - 1]);
        if (c > h){
            cout << i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}