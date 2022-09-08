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

const int max_n = 111, inf = 1111111111;

int n;
vector < pair <int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int x = 1;
    for (int i = 1; i <= n; ++i) {
        if ((n - x) * x < (n - i) * i) {
            x = i;
        }
    }
    cout << (n - x) * x << endl;
    for (int i = x + 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            cout << i << ' ' << j << endl;
        }
    }
    return 0;
}