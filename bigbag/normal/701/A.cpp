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

const int max_n = 111, inf = 1111111111;

int n, sum, a[max_n], used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sum /= (n / 2);
    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            for (int j = 0; j < n; ++j) {
                if (used[j] == 0 && a[i] + a[j] == sum) {
                    used[j] = 1;
                    cout << j + 1 << " ";
                    break;
                }
            }
            cout << i + 1 << endl;
        }
    }
    return 0;
}