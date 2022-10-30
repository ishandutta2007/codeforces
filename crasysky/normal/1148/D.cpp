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
pair < int, int > a[maxn], b[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), m1 = 0, m2 = 0;
    for (int i = 1; i <= n; ++ i){
        int x = read(), y = read();
        if (x < y)
            a[++ m1] = mp(x, i);
        else
            b[++ m2] = mp(y, i);
    }
    sort(a + 1, a + 1 + m1);
    sort(b + 1, b + 1 + m2);
    if (m1 > m2){
        cout << m1 << endl;
        for (int i = m1; i; -- i)
            printf("%d ", a[i].se);
    }
    else{
        cout << m2 << endl;
        for (int i = 1; i <= m2; ++ i)
            printf("%d ", b[i].se);
    }
}