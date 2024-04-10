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

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; ++j) {
                cout << "#";
            }
            cout << endl;
        } else {
            if (i % 4 == 3) {
                cout << "#";
            }
            for (int j = 1; j < m; ++j) {
                cout << ".";
            }
            if (i % 4 == 1) {
                cout << "#";
            }
            cout << endl;
        }
    }
    return 0;
}