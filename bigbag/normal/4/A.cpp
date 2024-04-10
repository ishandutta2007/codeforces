#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0 && (n - i) % 2 == 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}