#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 44444, inf = 111111111;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] + b[i] == a[j] && a[j] + b[j] == a[i]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}