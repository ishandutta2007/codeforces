#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define fi first
#define se second
using namespace std;
pair <long long, long long> a[1000006], b[1000006];
int cnt[1000006];
bool del[1000006];
long long read(){
    long long c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        a[i].fi = read();
    for (int i = 1; i <= n; ++ i)
        a[i].se = read();
    sort(a + 1, a + 1 + n);
    int m = 0;
    b[++ m] = a[1], cnt[m] = 1;
    for (int i = 2; i <= n; ++ i)
        if (a[i].fi == a[i - 1].fi)
            b[m].se += a[i].se, ++ cnt[m];
        else
            b[++ m] = a[i], cnt[m] = 1;
    long long ans = 0;
    for (int i = m; i; -- i){
        bool flag = false;
        for (int j = i + 1; j <= m; ++ j)
            if (! del[j] && (b[i].fi & b[j].fi) == b[i].fi){
                flag = true;
                break;
            }
        if (cnt[i] == 1 && ! flag)
            del[i] = true;
        else
            ans += b[i].se;
    }
    cout << ans << endl;
}