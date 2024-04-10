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
#define maxn 100
#define inf 0x3f3f3f3f

int n, q, x[maxn][maxn];

vector<PII> sol[maxn];

int32_t main(){
	cin >> n;
    for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) sol[i + j].emplace_back(i, j);
    
    int pos = 0;
    for (int i = 1; i <= n + n - 2; ++ i) {
        pos ++;
        for (int j = 0; j < sol[i].size(); j += 2) {
            x[sol[i][j].F][sol[i][j].S] = (1ll << pos);
        }
    }
    for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) cout << x[i][j] << " \n"[j + 1 == n];
    fflush(stdout);
    cin >> q;
    while (q --) {
        int sum;
        cin >> sum;
        int v1 = 0, v2 = 0;
        cout << v1 + 1 << " " << v2 + 1 << endl;
        fflush(stdout);
        for (int i = 1; i <= n + n - 2; ++ i) {
            if (x[v1 + 1][v2]) {
                if (sum & x[v1 + 1][v2]) v1 ++;
                else v2 ++;
            } else if (x[v1][v2 + 1]) {
                if (sum & (x[v1][v2 + 1])) v2 ++;
                else v1 ++;
            } else {
                if (v1 + 1 == n) v2 ++;
                else v1 ++;
            }
            cout << v1 + 1 << " " << v2 + 1 << endl;
            fflush(stdout);
        }
    }
    return 0;
}