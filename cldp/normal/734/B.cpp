#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 1010;


int main() {
    ios_base::sync_with_stdio(false);
    long long k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    k5 = min(k5, k6);
    k5 = min(k5, k2);
    long long ans = 0;
    
    ans += k5 * 256;
    k2 -= k5;
    k2 = min(k2, k3);
    ans += k2 * 32;
    cout << ans << endl;
    
    return 0;
}