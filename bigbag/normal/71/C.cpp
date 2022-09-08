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

const int max_n = 111111, inf = 111111111;

int n, a[max_n];
vector<int> v;

bool good(int poz, int r) {
    for (int i = poz; i <= n; i += r) {
        if (a[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int r = 1; r <= n; ++r) {
        if (n / r >= 3 && n % r == 0) {
            v.push_back(r);
        }
    }
    for (int j = 0; j < v.size(); ++j) {
        for (int i = 1; i <= v[j]; ++i) {
            if (good(i, v[j])) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}