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
 
const int max_n = 1e5;
 
int n, m, k;
int a[max_n];
int b[max_n];
pair<int, int> c[2 * max_n];
ll up_to[2 * max_n];
ll down_to[2 * max_n];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    
    for (int i = 0; i < n; ++i) {
        c[i].first = a[i];
        c[i].second = 0;
    }
    for (int i = 0; i < m; ++i) {
        c[i + n].first = b[i];
        c[i + n].second = 1;
    }
    
    k = n + m;
    sort(c, c + k);
    
    ll cnt = 0;
    ll sum = 0;
    for (int i = 0; i < k; ++i) {
        if (c[i].second == 0) {
            ++cnt;
            sum += c[i].first;
        }
        up_to[i] = cnt * c[i].first - sum;
    }
    
    cnt = sum = 0;
    for (int i = k - 1; i >= 0; --i) {
        if (c[i].second == 1) {
            ++cnt;
            sum += c[i].first;
        }
        down_to[i] = sum - cnt * c[i].first;
    }
    
    ll ans = up_to[0] + down_to[0];
    for (int i = 1; i < k; ++i)
        ans = min(ans, up_to[i] + down_to[i]);
    
    cout << ans << endl;

    return 0;
}