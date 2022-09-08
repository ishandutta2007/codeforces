#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111;
const long long inf = 1011011011022022022LL;

int n, pos, a[max_n];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (pos + 1 < n && a[pos] < a[pos + 1]) {
        ++pos;
    }
    while (pos + 1 < n && a[pos] == a[pos + 1]) {
        ++pos;
    }
    while (pos + 1 < n && a[pos] > a[pos + 1]) {
        ++pos;
    }
    if (pos + 1 == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}