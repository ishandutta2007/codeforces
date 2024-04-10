#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
const int P = (1e9) + 7;
int a[1003][1003];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int h = read(), w = read();
    for (int i = 1; i <= h; ++ i){
        int x = read();
        for (int j = 1; j <= x; ++ j)
            a[i][j] = 1;
        a[i][x + 1] = 2;
    }
    for (int i = 1; i <= w; ++ i){
        int x = read();
        for (int j = 1; j <= x; ++ j){
            if (a[j][i] == 2){
                cout << 0 << endl;
                return 0;
            }
            a[j][i] = 1;
        }
        if (a[x + 1][i] == 1){
            cout << 0 << endl;
            return 0;
        }
        a[x + 1][i] = 2;
    }
    int ans = 1;
    for (int i = 1; i <= h; ++ i)
        for (int j = 1; j <= w; ++ j)
            if (a[i][j] == 0)
                ans = 1LL * ans * 2 % P;
    cout << ans << endl;
    return 0;
}