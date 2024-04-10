#include <map>
#include <set>
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

const int max_n = 11111, inf = 111111111;

int n, a[max_n], used[5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int sum = 0, k = a[i];
        while (k != 0) {
            sum += k % 10;
            k /= 10;
        }
        used[sum % 3]++;
    }
    cout << used[0] / 2 + min(used[1], used[2]);
    return 0;
}