#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

typedef long long ll;

const int max_m = 5e4 + 10;
const int max_n = 5;

int t[max_m][max_n];
int n, m;
ll r[max_m][max_n + 1];

int main()
{
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);
    
    
    scanf("%d%d", &m, &n);
    
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &t[i][j]);
        
    r[0][0] = 0;
    for (int i = 0; i < n; ++i)
        r[0][i + 1] = r[0][i] + t[0][i];
    for (int i = 1; i < m; ++i) {
        r[i][0] = 0;
        for (int j = 0; j < n; ++j)
            r[i][j + 1] = max(r[i][j], r[i - 1][j + 1]) + t[i][j];
    }
    
    ios_base::sync_with_stdio(false);
    
    for (int i = 0; i < m; ++i)
        cout << r[i][n] << " ";
    cout << endl;

    return 0;
}