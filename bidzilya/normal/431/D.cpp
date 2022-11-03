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
using namespace std;
  
typedef long long ll;

const int max_bit = 64;

inline int bit(ll mask, int x)
{
    return (mask >> x) & 1;
}

ll C[max_bit + 1][max_bit + 1];

ll f(ll n, int k, int pos)
{
    if (pos == 0) {
        return k == bit(n, pos);
    }
    if (bit(n, pos) == 0) {
        return f(n, k, pos - 1);
    }
    ll res = f(n, k - 1, pos - 1);
    res += C[pos][k];
    return res;
}

ll f(ll n, int k)
{
    return f(n, k, max_bit - 1);
}

ll m;
int k;

ll f(ll n)
{
    return f(n, k);
}

ll F(ll n)
{
    return f(n * 2) - f(n);
}

int main()
{
    C[0][0] = 1;
    for (int i = 1; i <= max_bit; ++i)
        C[i][0] = 1;
    for (int j = 1; j <= max_bit; ++j)
        C[0][j] = 0;
    for (int i = 1; i <= max_bit; ++i)
        for (int j = 1; j <= max_bit; ++j)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    cin >> m >> k;
    
    ll lo = 1;
    ll hi = 1e18;
    while (lo <= hi) {
        ll mi = (lo + hi) >> 1;
        
        ll r = F(mi);
        if (r > m) {
            hi = mi - 1;
        } else if (r < m) {
            lo = mi + 1;
        } else {
            cout << mi << endl;
            break;
        }
    }

    return 0;
}