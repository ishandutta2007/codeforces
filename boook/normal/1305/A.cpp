#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 2000
#define inf 0x3f3f3f3f

int t, n, a[maxn], b[maxn];

int32_t main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; ++ i) cin >> a[i];
        for (int i = 1; i <= n; ++ i) cin >> b[i];
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; ++ i) cout << a[i] << " \n"[i == n];
        for (int i = 1; i <= n; ++ i) cout << b[i] << " \n"[i == n];
    }

    return 0;
}