#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define int long long
#define maxn 200000 + 100
#define inf 0x3f3f3f3f

int n, x[maxn], y[maxn], sol[maxn];
map<int, int> cc;

int cmp(int a, int b) {
    return y[a] > y[b];
}

int Find(int now) {
    if (cc.find(now) != cc.end())
        return cc[now] = Find(cc[now]);
    else return now;
}
int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n;
    long long ans = 0;

    for (int i = 1; i <= n; ++ i) cin >> x[i];
    for (int i = 1; i <= n; ++ i) cin >> y[i];
    for (int i = 1; i <= n; ++ i) sol[i] = i;
    sort(sol + 1, sol + 1 + n, cmp);

    for (int i = 1; i <= n; ++ i) {
        int idx = sol[i];
        int to = Find(x[idx]);
        ans += (to - x[idx]) * y[idx];
        cc[to] = to + 1;
    }
    cout << ans << endl;
    return 0;
}