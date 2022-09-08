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

int n, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> t;
    if (t < 10) {
        for (int i = 0; i < n; ++i) {
            cout << t;
        }
        cout << endl;
    } else {
        if (n == 1) {
            cout << -1 << endl;
        } else {
            cout << 1;
            for (int i = 1; i < n; ++i) {
                cout << 0;
            }
            cout << endl;
        }
    }
    return 0;
}