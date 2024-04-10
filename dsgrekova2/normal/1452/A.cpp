#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;

void PolnalyubviTop(){
    int x, y;
    cin >> x >> y;
    x = abs(x);
    y = abs(y);
    int t = min(x, y);
    int t2 = max(x, y) - t;
    t2 = max(t2 * 2 - 1, 0ll);
    cout << t * 2 + t2 << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}