#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n, k, m, d;
    cin >> n >> k >> m >> d;
    int cds = -1;
    for (int take=1; take <= d; take++){
        int R = n / ((take-1)*k + 1);
        int L = n / (take*k + 1);
        if (n % (take*k + 1) == 0) L++;
        R = min(R, m);
        if (R==0) break;
        if (L > R) continue;
        cds = max(cds, R*take);
    }
    cout << cds;
}