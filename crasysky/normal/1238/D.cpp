#include <algorithm>
#include <iostream>
#include <cstdio>
#define maxn 1000006
using namespace std;
int a[maxn], l[maxn];
string s;
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read();
    cin >> s;
    for (int i = 1; i <= n; ++ i)
        a[i] = s[i - 1] == 'B';
    l[1] = 1;
    for (int i = 2; i <= n; ++ i)
        if (a[i] == a[i - 1])
            l[i] = l[i - 1] + 1;
        else
            l[i] = 1;
    long long ans = 1LL * n * (n - 1) / 2;
    for (int i = 2; i <= n; ++ i)
        if (a[i] != a[i - 1])
            ans -= l[i - 1];
    l[n] = 1;
    for (int i = n - 1; i; --i)
        if (a[i] == a[i + 1])
            l[i] = l[i + 1] + 1;
        else
            l[i] = 1;
    for (int i = 1; i < n; ++ i)
        if (a[i] != a[i + 1])
            ans -= l[i + 1];
    for (int i = 1; i < n; ++ i)
        if (a[i] != a[i + 1])
            ++ ans;
    cout << ans << endl;
}