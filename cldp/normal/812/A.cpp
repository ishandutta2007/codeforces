#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);
 
 
int main() {
    ios_base::sync_with_stdio(false);
    int x[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) cin >> x[i][j];
    }
    
    bool flag = false;
    for (int i = 0; i < 4; ++i) {
        if (x[i][3] == 0) continue;
        if (x[i][0] || x[i][1] || x[i][2]) flag = true;
        if (x[(i + 1) % 4][0] || x[(i + 3) % 4][2]) flag = true;
        if (x[(i + 2) % 4][1]) flag = true;
    }
 
    if (flag) cout << "YES" << endl; else cout << "NO" << endl;
 
    return 0;
}