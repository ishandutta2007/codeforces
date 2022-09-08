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
    int max1 = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (max1 < s1[i] - '0') {
            max1 = s1[i] - '0';
        }
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (max1 < s2[i] - '0') {
            max1 = s2[i] - '0';
        }
    }
    int k = max1 + 1;
    while (s1.length() < s2.length()) {
        s1 = "0" + s1;
    }
    while (s2.length() < s1.length()) {
        s2 = "0" + s2;
    }
    int ans = s1.length(), p = 0;
    for (int i = s1.length() - 1; i >= 0; --i) {
        int x = (s1[i] - '0' + s2[i] - '0' + p);
        p = x / k;
    }
    if (p != 0) {
        ++ans;
    }
    cout << ans << endl;
    return 0;
}