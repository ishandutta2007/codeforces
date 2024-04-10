#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int maxn = 1000006;
int a[maxn];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int T = read();
    while (T --){
        int n = read();
        for (int i = 1; i <= n; ++ i)
            a[i] = read();
        sort(a + 1, a + 1 + n);
        cout << min(a[n - 1] - 1, n - 2) << endl;
    }
}