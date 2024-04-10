#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <random>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double n , m;
    cin >> n >> m;
    double huy = m ? (int)  (n - (1.0 + sqrt(8 * m + 1)) / 2.0) : n;
    cout << max(0LL, (int) (n - 2 * m)) << " " << huy << "\n";
}