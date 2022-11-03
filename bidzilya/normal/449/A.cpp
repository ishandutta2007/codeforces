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

ll get_res(int n, int m, int k)
{
    int x = min(k, n - 1);
    k -= x;
    n /= (x + 1);
    int y = min(k, m - 1);
    m /= (y + 1);
    return 1LL * n * m;
}

int main()
{
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    int n, m, k;
    
    cin >> n >> m >> k;
    
    if (n + m - 2 < k) {
        cout << -1 << endl;
        return 0;
    }

    cout << max(get_res(n, m, k), get_res(m, n, k)) << endl;

    return 0;
}