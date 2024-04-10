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

const int max_n = 222222, inf = 1111111111;

int n, x, last;
long long s[2];
vector<int> v[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        if (x > 0) {
            v[0].push_back(x);
            s[0] += x;
            last = 1;
        } else {
            v[1].push_back(-x);
            s[1] += -x;
            last = 2;
        }
    }
    if (s[0] > s[1]) {
        cout << "first" << endl;
        return 0;
    }
    if (s[0] < s[1]) {
        cout << "second" << endl;
        return 0;
    }
    int f = -1, fin = min(v[0].size(), v[1].size());
    for (int i = 0; i < fin; ++i) {
        if (v[0][i] != v[1][i]) {
            f = i;
            break;
        }
    }
    int ans;
    if (f == -1) {
        if (v[0].size() > v[1].size()) {
            ans = 1;
        }
        if (v[0].size() < v[1].size()) {
            ans = 2;
        }
        if (v[0].size() == v[1].size()) {
            ans = last;
        }
        if (ans == 1) {
            cout << "first" << endl;
        } else {
            cout << "second" << endl;
        }
        return 0;
    }
    if (v[0][f] > v[1][f]) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }
    return 0;
}