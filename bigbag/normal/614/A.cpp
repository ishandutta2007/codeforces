#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const long long inf = 1111111111111111111LL;

long long l, r, k, f;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> l >> r >> k;
    long long pw = 1;
    while (true) {
        if (l <= pw && pw <= r) {
            cout << pw << " ";
            f = 1;
        }
        if (pw > inf / k + 1) {
            break;
        }
        pw *= k;
    }
    if (f == 0) {
        cout << -1 << endl;
    }
    return 0;
}