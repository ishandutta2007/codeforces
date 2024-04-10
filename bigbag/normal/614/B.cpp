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

const int max_n = 1, inf = 1111111111;

int n;
string a, s, t;

bool ok() {
    if (a[0] != '1') {
        return false;
    }
    for (int i = 1; i < a.length(); ++i) {
        if (a[i] != '0') {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    s = "1";
    while (n--) {
        cin >> a;
        if (a == "0") {
            cout << 0 << endl;
            return 0;
        }
        if (ok()) {
            t += a.substr(1);
        } else {
            s = a;
        }
    }
    cout << s << t << endl;
    return 0;
}