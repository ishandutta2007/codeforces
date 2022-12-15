#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int ans = n;
        for (int i = 1; i <= min(k, int(sqrt(n))); i++) {
            if (n % i == 0) {
                ans = min(ans, n / i);
                if (n / i <= k) ans = min(ans, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}