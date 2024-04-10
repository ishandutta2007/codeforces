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

int n, st;
vector<int> a, b;

vector<int> solve(int n) {
    int d = 365;
    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)) {
        ++d;
    }
    vector<int> res;
    for (int i = 0; i < d; ++i) {
        res.push_back(st);
        ++st;
        st %= 7;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    a = solve(n);
    while (true) {
        ++n;
        b = solve(n);
        if (a == b) {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}