#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 100
#define inf 1900000000

int n, k, c[maxn], sol[maxn], nol[maxn];

unsigned int g[maxn][maxn], d[maxn][maxn][7];

int32_t main(){
    double t1 = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) 
        for (int j = 1; j <= n; ++ j)
            cin >> g[i][j];
    k >>= 1;
    int counter = 0;
    unsigned int ans = 1900000000;


    while (1) {
        ++ counter;
        if ((counter & 7) == 0) {
            double t2 = clock();
            if((t2 - t1) / CLOCKS_PER_SEC >= 2.9) break;
        }
        for (int i = 2; i <= n; ++ i) 
            c[i] = uniform_int_distribution<int>(0, 1)(rng);

        int pos = 0, po2 = 0;
        for (int i = 1; i <= n; ++ i) {
            if (c[i] == 0)
                 sol[pos ++] = i;
            else nol[po2 ++] = i;
        }

        for (int i = 0; i < pos; ++ i)
            for (int j = 0; j < pos; ++ j)
                d[sol[i]][sol[j]][1] = inf;

        for (int i = 0; i < pos; ++ i)
            for (int j = 0; j < pos; ++ j)
                for (int ii = 0; ii < po2; ++ ii)
                    d[sol[i]][sol[j]][1] = min(d[sol[i]][sol[j]][1], g[sol[i]][nol[ii]] + g[nol[ii]][sol[j]]);

        for (int tt = 2; tt <= k; ++ tt) {
            for (int i = 0; i < pos; ++ i)
                for (int j = 0; j < pos; ++ j)
                    d[sol[i]][sol[j]][tt] = inf;
            for (int i = 0; i < pos; ++ i)
                for (int j = 0; j < pos; ++ j)
                    for (int ii = 0; ii < pos; ++ ii)
                        d[sol[i]][sol[j]][tt] = min(d[sol[i]][sol[j]][tt], 
                            d[sol[i]][sol[ii]][tt - 1] + d[sol[ii]][sol[j]][1]);
        }
        ans = min(ans, d[1][1][k]);
    }
    // cout << counter << endl;
    cout << ans << "\n";
    return 0;
}