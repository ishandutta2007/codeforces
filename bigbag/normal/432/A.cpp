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

const int max_n = 2222, inf = 1111111111;

int n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (5 - a[i] >= k) {
            ++cnt;
        }
    }
    cout << cnt / 3 << endl;
    return 0;
}