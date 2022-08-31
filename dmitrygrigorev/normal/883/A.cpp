#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, d;
    cin >> n >> m >> a >> d;
    vector<int> v(m);
    for (int i=0; i < m; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int counts = d / a + 1;
    int now = 0;
    int ans = 0;
    int i = 0;
    while (i < m){
        int come = v[i] / a - now;
        if (v[i] / a >= n){
            int ost = n - now;
            int dop = (counts - ost%counts) % counts;
            int q = (n+dop) * a + d%a;
            if (now == n) q = n*a;
            while (i < m && v[i] <= q) i++;
            while (i < m){
                ans++;
                int V = v[i];
                while (i < m && v[i] - V <= d) i++;
            }
            break;
        }
        if (come % counts == 0 && (v[i] % a > d % a || come == 0)){
            ans += come / counts;
            int finish = v[i] + d;
            ans++;
            now = min(n, finish / a);
            //cout << come << endl;
            while (i < m && v[i] <= finish) i++;
        }
        else i++;
    }
    //cout << ans << endl;
    ans += (n - now) / counts + ((n-now) % counts != 0);
    cout << ans << endl;
    return 0;
}