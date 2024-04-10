#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

ll n, m, k;

ll get_lower_or_equal(ll x)
{
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        res += min(x / i, m);
    }
    return res;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;

    if (k == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    ll li = 2;
    ll hi = n * m;
    while (li <= hi) {
        ll mi = (li + hi) >> 1;
    
        ll g1 = get_lower_or_equal(mi);
        ll g2 = get_lower_or_equal(mi - 1);

        if (g2 < k && g1 >= k) {
            cout << mi << endl;
            break;
        }
        
        if (g1 >= k && g2 >= k) {
            hi = mi - 1;
        } else if (g1 < k) {
            li = mi + 1;
        }
    }

    return 0;
}