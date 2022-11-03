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

const int max_n = 1e5 + 10;

int n;
int a[max_n];
int l[max_n];
int r[max_n];

int main()
{
    ios_base::sync_with_stdio(false);
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        r[i] = 1;
        if (a[i] < a[i + 1]) 
            r[i] = 1 + r[i + 1];
    }
    
    l[0] = 1;
    for (int i = 1; i < n; ++i) {
        l[i] = 1;
        if (a[i] > a[i - 1]) 
            l[i] = 1 + l[i - 1];
    }
    
    int ans = 2;
    for (int i = 0; i + 1 < n; ++i)
        if (a[i] < a[i + 1]) {
            ans = max(ans, r[i]);
        } else {
            ans = max(ans, 1 + r[i + 1]);
        }
    for (int i = 1; i < n; ++i) 
        if (a[i] > a[i - 1]) {
            ans = max(ans, l[i]);
        } else {
            ans = max(ans, 1 + l[i - 1]);
        }
    
    for (int i = 1; i + 1 < n; ++i)
        if (a[i - 1] + 1 < a[i + 1]) {
            ans = max(ans, 1 + l[i - 1] + r[i + 1]);
        }
    
    cout << ans << endl;
    
    return 0;
}