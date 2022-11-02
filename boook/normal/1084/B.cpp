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
#define maxn 10000
#define inf 0x3f3f3f3f

int n, s, x[maxn];

int Judge(int lim) {
    int total = 0;
    for (int i = 1; i <= n; ++ i)
        if (x[i] >= lim) total += x[i] - lim;
        else return 0;
    return total >= s;
}

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> n >> s;
    for (int i = 1; i <= n; ++ i)
        cin >> x[i];
    int ans = -1;
    for (int i = 40; i >= 0; -- i) {
        int to = ans + (1ll << i);
        if (Judge(to)) ans = to;
    }
    cout << ans << "\n";
    return 0;
}