#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, k; 
    cin >> n >> k;
    if (k == n) {
        cout << -1 << endl;
        return 0;
    }
    if (k + 1 == n) {
        cout << 1 << " ";
        for (int i = 2; i <= n; ++i)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    cout << k + 2 << " ";
    for (int i = 2; i <= k + 1; ++i)
        cout << i << " ";
    for (int i = k + 2; i < n; ++i)
        cout << i + 1 << " ";
    cout << 1 << endl;
    
    return 0;
}