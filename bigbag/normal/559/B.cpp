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

char s1[222222], s2[222222];

bool f(int l1, int r1, int l2, int r2) {
    //cout << l1 << " " << r1 << "  " << l2 << " " << r2 << endl;
    int len = r1 - l1 + 1, res = 0;
    for (int i = l1; i <= r1; ++i) {
        if (s1[i] != s2[l2 + i - l1]) {
            res = 1;
            break;
        }
    }
    if (res == 0) {
        return true;
    }
    if (len % 2) {
        return false;
    }
    len /= 2;
    if (f(l1, l1 + len - 1, l2, l2 + len - 1)) {
        return f(l1 + len, r1, l2 + len, r2);
    }
    if (f(l1, l1 + len - 1, l2 + len, r2)) {
        return f(l1 + len, r1, l2, l2 + len - 1);
    }
    //cout << l1 << " " << r1 << " false " << l2 << " " << r2 << endl;
    return false;
}

int main() {
    scanf("%s%s", s1, s2);
    if (f(0, strlen(s1) - 1, 0, strlen(s1) - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}