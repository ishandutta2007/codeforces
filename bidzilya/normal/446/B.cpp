#include <cstdio>
#include <cstdlib>
#include <cmath>
  
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
  
typedef long long ll;

const int max_n = 1e3 + 1;
const int max_k = 1e6 + 10;

int a[max_n][max_n];
int n, m, k, p;

ll str_ans[max_k];
ll stl_ans[max_k];

priority_queue<ll> q1, q2;

int main()
{
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &k, &p);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j)
            sum += a[i][j];
        q1.push(sum);
    }
    str_ans[0] = 0;
    for (int step = 1; step <= k; ++step) {
        ll temp = q1.top(); q1.pop();
        str_ans[step] = str_ans[step - 1] + temp;
        q1.push(temp - 1LL * m * p);
    }
    for (int j = 0; j < m; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) 
            sum += a[i][j];
        q2.push(sum);
    }
    stl_ans[0] = 0;
    for (int step = 1; step <= k; ++step) {
        ll temp = q2.top(); q2.pop();
        stl_ans[step] = stl_ans[step - 1] + temp;
        q2.push(temp - 1LL * n * p);
    }
    ll ans;
    bool found = false;
    for (int cstr = 0; cstr <= k; ++cstr) {
        ll cans = str_ans[cstr] + stl_ans[k - cstr] - 1LL * cstr * (k - cstr) * p;
        if (!found || cans > ans) {
            ans = cans;
            found = true;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}