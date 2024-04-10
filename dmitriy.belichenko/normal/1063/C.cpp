#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <deque>
#include <ctime>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cassert>
#include <cstring>

#define fi first
#define se second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    int n;
    cin >> n;

    int a = 5;
    int b = 1000 * 1000 * 1000 - 5;

    bool fl = false;
    
    cout << ((a + b) / 2) << ' ' << (int)1e9 << endl;
    string s;
    cin >> s;

    if (s == "black") {
        fl = true;
    }

    n--;
    while (n > 0) {
        int m = (a + b) / 2;
        cout << m << ' ' << 1 << endl;
        cin >> s;

        if (s == "black") {
            b = m;
        } else {
            a = m;
        }
        n--;
    }

    if (!fl) {
        cout << a << ' ' << 0 << ' ' << b << ' ' << 2 << endl;
    } else {
        cout << b << ' ' << 0 << ' ' << a << ' ' << 2 << endl;
    }
    return 0;
}