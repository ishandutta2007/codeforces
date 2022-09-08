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

const int max_n = 200002, inf = 111111111;

long long n, a[max_n], sum1[max_n], sum2[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        sum1[i] = sum1[i - 1];
        if (a[i - 1] == 1) {
            ++sum1[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        sum2[i] = sum2[i + 1];
        if (a[i + 1] == 0) {
            ++sum2[i];
        }
    }
    /*for (int i = 0; i < n; ++i) {
        cout << sum1[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << sum2[i] << ' ';
    }
    cout << endl;*/
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ans += sum1[i];
        } else {
            ans += sum2[i];
        }
    }
    cout << ans / 2 << endl;
    return 0;
}