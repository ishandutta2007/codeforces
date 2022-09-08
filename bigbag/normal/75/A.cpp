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

int a, b, c;

int norm(int x) {
    vector<int> v;
    while (x != 0) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != 0) {
            res = res * 10 + v[i];
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a >> b;
    c = a + b;
    a = norm(a);
    b = norm(b);
    c = norm(c);
    if (a + b == c) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}