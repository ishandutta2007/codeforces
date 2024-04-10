#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 3333, inf = 111111111;

int n, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i < 3333; ++i) {
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}