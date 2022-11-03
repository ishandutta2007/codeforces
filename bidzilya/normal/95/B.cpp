#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int max_n = 1e5 + 100;

string s;
int n, m;
int ans[max_n];

void build(int pos, int c4, int c7) {
    for (int i = 0; i < c4; ++i) 
        ans[pos + i] = 4;
    for (int i = 0; i < c7; ++i)
        ans[pos + c4 + i] = 7;
}

bool try_to_build(int pos, int c4, int c7) {
    if (pos == n)
        return true;
    if (s[pos] > '7') 
        return false;
    if (s[pos] < '4') {
        build(pos, c4, c7);
        return true;
    }
    if (s[pos] == '4') {
        if (c4 > 0) {
            ans[pos] = 4;
            if (try_to_build(pos + 1, c4 - 1, c7)) 
                return true;
        }
        if (c7 > 0) {
            ans[pos] = 7;
            build(pos + 1, c4, c7 - 1);
            return true;
        }
        return false;
    }
    if (s[pos] == '5' || s[pos] == '6') {
        if (c7 == 0)
            return false;
        ans[pos] = 7;
        build(pos + 1, c4, c7 - 1);
        return true;
    }
    if (s[pos] == '7') {
        if (c7 > 0) {
            ans[pos] = 7;
            if (try_to_build(pos + 1, c4, c7 - 1))
                return true;
        }
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    if (n & 1) {
        build(0, (n + 1) >> 1, (n + 1) >> 1);
        m = n + 1;
    } else {
        if (!try_to_build(0, n >> 1, n >> 1)) {
            build(0, (n >> 1) + 1, (n >> 1) + 1);
            m = n + 2;
        } else {
            m = n;
        }
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i];
    cout << endl;
    return 0;
}