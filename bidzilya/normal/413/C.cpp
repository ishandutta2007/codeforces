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

const int max_n = 100;

int n, m;
int auc[max_n];
int a[max_n];

int main()
{
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        --b;
        auc[b] = 1;
    }
    
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        if (!auc[i])
            ans += a[i];

    vector<int> b;
    for (int i = 0; i < n; ++i)
        if (auc[i])
            b.push_back(a[i]);
    
    sort(b.begin(), b.end());
    
    for (int i = (int) b.size() - 1; i >= 0; --i)
        if (b[i] < ans) {
            ans += ans;
        } else {
            ans += b[i];
        }

    cout << ans << endl;

    return 0;
}