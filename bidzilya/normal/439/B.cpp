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
    
int c[max_n];
int n, x;

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n >> x;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(c, c + n);
    for (int i = 0; i < n; ++i) {
        ans += 1LL * c[i] * x;
        x = max(1, x - 1);
    }
    
    cout << ans << endl;

    return 0;
}