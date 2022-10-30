#include <algorithm>
#include <iostream>
#include <cstdio>
#define ll unsigned long long
using namespace std;
int a[1000006];
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
        int n = read(), r = read();
        for (int i = 1; i <= n; ++ i)
            a[i] = read();
        sort(a + 1, a + 1 + n);
        n = unique(a + 1, a + 1 + n) - a - 1;
        int c = 0, d = 0;
        for (int i = n; i; -- i)
            if (a[i] - 1LL * d * r > 0)
                ++ c, ++ d;
        cout << c << endl;
    }
}