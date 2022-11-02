/*input
4
2 6 7 8
*/
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 1000900
#define inf 0x3f3f3f3f

int n, x[maxn], ans[maxn];

inline int rit(){
    int res = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}

int32_t main(){
    n = rit();
    int sum = 0;
    for (int i = 1; i <= n; ++ i) x[i] = rit(), sum += x[i];

    int now = 0;
    for (int i = 60; i >= 0; -- i) {
        int to = now + (1ll << i);
        int v1 = to + to + n - 1;
        int lt = n;
        if (1 <= sum * 2 / lt / v1) now = to;
    }

    for (int i = 1; i <= n; ++ i) ans[i] = now + i - 1, sum -= ans[i];
    for (int i = 1; i <= n; ++ i) if (sum) sum --, ans[i] ++;
    for (int i = 1; i <= n; ++ i) printf("%lld%c", ans[i], " \n"[i == n]);
    return 0;
}