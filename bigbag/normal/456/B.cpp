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

const int max_n = 100011, max_c = 27, inf = 1111111111;

string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        x = (x * 10 + s[i] - '0') % 4;
    }
    int a, b, c, d;
    a = 1;
    if (x == 0) {
        b = 1;
        c = 1;
        d = 1;
    }
    if (x == 1) {
        b = 2;
        c = 3;
        d = 4;
    }
    if (x == 2) {
        b = 4;
        c = 4;
        d = 1;
    }
    if (x == 3) {
        b = 3;
        c = 2;
        d = 4;
    }
    cout << (a + b + c + d) % 5 << endl;
    return 0;
}