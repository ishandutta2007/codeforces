#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

const long long MAXW = 1e6 + 100;
long long wgt[MAXW];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("input.txt", "w", stdout);
//    cout << 1e6 << endl;
//    for (int i = 0; i < 1e6; i++)
//        cout << 1e6 - 1<< ' ';
    iostream::sync_with_stdio(false);
    int n, i, o;
    for (i = 0; i < MAXW - 1; i++)
    {
        wgt[i] = 0;
    }
    cin >> n;
//    m.resize(n);
    for (i = 0; i < n; i++)
    {
        cin >> o;
        wgt[o]++;
    }
    int ans = 0;
    for (i = 0; i < MAXW - 1; i++)
    {
        wgt[i + 1] += (wgt[i] >> 1);
//        if (wgt[i] != 0) cout << wgt[i] << ' ' << (wgt[i] | 1) << endl;
        if ((wgt[i] | 1) ==  wgt[i])
            ans++;
    }
    cout << ans;
    return 0;
}