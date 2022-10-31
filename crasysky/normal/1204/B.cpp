#include <iostream>
#include <cstdio>
using namespace std;

int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), l = read(), r = read();
    long long ans = n - l + 1;
    for (int i = 2, s = 2; i <= l; ++ i, s <<= 1)
        ans += s;
    cout << ans << " ";
    ans = (1 << r - 1) * (n - r + 1);
    for (int i = 1, s = 1; i < r; ++ i, s <<= 1)
        ans += s;
    cout << ans << endl;
}