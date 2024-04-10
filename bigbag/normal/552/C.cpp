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

int a, b;
vector<int> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    while (b) {
        v.push_back(b % a);
        b /= a;
    }
    for (int i = 0; i < 100; ++i) {
        v.push_back(0);
    }
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (-1 <= v[i] && v[i] <= 1) {
            continue;
        }
        if (v[i] == a - 1 || v[i] == a || v[i] == a + 1) {
            ++v[i + 1];
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}