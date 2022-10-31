#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
int a[1003];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int l = read(), r = read();
    for (int i = l; i <= r; ++ i){
        int t = 0, x = i;
        while (x){
            a[++ t] = x % 10;
            x /= 10;
        }
        sort(a + 1, a + 1 + t);
        int m = unique(a + 1, a + 1 + t) - a - 1;
        if (m == t){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}