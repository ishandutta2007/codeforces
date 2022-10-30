#include <algorithm>
#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
int a[maxn], b[maxn], l[maxn], r[maxn];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int T;
    cin >> T;
    while (T --){
        int h = read(), n = read();
        for (int i = 1; i <= n; ++ i)
            a[i] = read();
        int c = 1;
        l[1] = r[1] = a[n];
        for (int i = n - 1; i; -- i)
            if (a[i] == a[i + 1] + 1)
                r[c] = a[i];
            else{
                ++ c;
                l[c] = r[c] = a[i];
            }
        int m = 0;
        if (l[1] != 1)
            b[++ m] = 0;
        if ((r[1] - l[1] + 1) % 2 == 1)
            b[++ m] = 1;
        else
            b[++ m] = 1, b[++ m] = 1;
        for (int i = 2; i <= c; ++ i){
            b[++ m] = 0;
            if ((r[i] - l[i] + 1) % 2 == 1)
                b[++ m] = 1;
            else
                b[++ m] = 1, b[++ m] = 1;
        }
        int ans = 0;
        for (int i = m; i >= 3; ){
            if (b[i - 1] == 1 && b[i - 2] == 0)
                ++ ans, i -= 2;
            else if (b[i - 1] == 0)
                -- i;
            else if (b[i - 2] == 1)
                i -= 2;
        }
        cout << ans << endl;
    }
}