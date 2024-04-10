#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int max_n = 1e6;

int n, m;
int x[max_n];


ll dl[max_n];
int cl[max_n];
ll dr[max_n];
int cr[max_n];

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", x + i);
    
    dl[0] = x[0];
    cl[0] = 1;
    int t = 1;
    for (int i = 1; i < n; ++i) {
        dl[i] = dl[i - 1];
        cl[i] = cl[i - 1];
        ++t;
        if (t > m) {
            t = 1;
            dl[i] += x[i];
            ++cl[i];
        }
    }
    
    dr[n - 1] = x[n - 1];
    cr[n - 1] = 1;
    t = 1;
    for (int i = n - 2; i >= 0; --i) {
        dr[i] = dr[i + 1];
        cr[i] = cr[i + 1];
        ++t;
        if (t > m) {
            t = 1;
            dr[i] += x[i];
            ++cr[i];
        }
    }
    
    ll ans = (dr[0] - 1LL * x[0] * cr[0]) * 2;

    for (int i = 1; i < n; ++i)
        ans = min(ans, ((1LL * x[i] * cl[i] - dl[i]) + (dr[i] - 1LL * x[i] * cr[i])) * 2);
    
    cout << ans << endl;
    
    return 0;
}