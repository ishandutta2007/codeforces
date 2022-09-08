#include <map>
#include <set>
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

string s1, s2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    int h1 = (s1[0] - '0') * 10 + s1[1] - '0';
    int m1 = (s1[3] - '0') * 10 + s1[4] - '0';
    int h2 = (s2[0] - '0') * 10 + s2[1] - '0';
    int m2 = (s2[3] - '0') * 10 + s2[4] - '0';
    int t1 = h1 * 60 + m1, t2 = h2 * 60 + m2;
    //cout << t1 << ' ' << t2 << endl;
    t1 -= t2;
    if (t1 < 0) {
        t1 += 1440;
    }
    int h = t1 / 60, m = t1 % 60;
    if (h < 10) {
        cout << 0;
    }
    cout << h << ":";
    if (m < 10) {
        cout << 0;
    }
    cout << m << endl;
    return 0;
}