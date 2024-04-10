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

const int max_n = 1, inf = 1011111111;

int n;

int solve(int n) {
    return n / 2 + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; ; ++i) {
        if (solve(i) == n) {
            cout << i << " " << 2 << endl;
            cout << 1 << " " << 2 << endl;
            return 0;
        }
    }
    return 0;
}