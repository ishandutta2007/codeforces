// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 500
#define inf 0x3f3f3f3f

int t, n, m, x[maxn][maxn], a[maxn][maxn];

int In(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}
int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
    cin >> t;
    while (t --) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j) cin >> x[i][j];
        int ok = 1;
        for (int i = 1; i <= n; ++ i) for (int j = 1; j <= m; ++ j) {
            int c = 0;
            if (In(i - 1, j)) c ++;
            if (In(i + 1, j)) c ++;
            if (In(i, j - 1)) c ++;
            if (In(i, j + 1)) c ++;
            a[i][j] = c;
            if (c < x[i][j]) ok = 0;
        }
        if (ok == 0) cout << "NO" << "\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; ++ i)
                for (int j = 1; j <= m; ++ j)
                    cout << a[i][j] << " \n"[j == m];
        }
    }
    return 0;
}