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

int n, ans, cnt;
string s1, s2;

void rec(int poz, int x) {
    if (poz == s2.length()) {
        ++cnt;
        if (x == n) {
            ++ans;
        }
        return;
    }
    if (s2[poz] == '+' || s2[poz] == '?') {
        rec(poz + 1, x + 1);
    }
    if (s2[poz] == '-' || s2[poz] == '?') {
        rec(poz + 1, x - 1);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == '+') {
            ++n;
        } else {
            --n;
        }
    }
    rec(0, 0);
    double x = ans;
    printf("%.10f\n", x / cnt);
    return 0;
}