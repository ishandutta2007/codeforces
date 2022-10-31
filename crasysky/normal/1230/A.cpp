#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[5];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    a[1] = read(), a[2] = read(), a[3] = read(), a[4] = read();
    int S = a[1] + a[2] + a[3] + a[4];
    for (int s = 1; s < 1 << 4; ++ s){
        int sum = 0;
        for (int i = 1; i <= 4; ++ i)
            if (s & (1 << i - 1))
                sum += a[i];
        if (sum == S - sum){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}