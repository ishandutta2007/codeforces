#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int maxn = 1000006;
int a[maxn], pl[maxn];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i){
        a[i] = read();
        pl[a[i]] = i;
    }
    int l = pl[n], r = pl[n];
    for (int i = n - 1; i; -- i){
        if (pl[i] == l - 1)
            -- l;
        else if (pl[i] == r + 1)
            ++ r;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}