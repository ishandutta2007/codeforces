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

const int max_m = 10;
const int max_n = 2e4;

int n, m, k;
int d[max_m], t[max_n];
int a[max_n][max_m];
int ans[max_n];

int main()
{
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    for (int i =0 ; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ++d[y];
        ++t[x];
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == 1) {
                ans[i] += d[j];
            }
    
    for (int i = 0; i < n; ++i)
        ans[i] -= t[i];
        
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << endl;



    return 0;
}