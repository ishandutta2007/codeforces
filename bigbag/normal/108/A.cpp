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
char c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%c%d", &a, &c, &b);
    while (true) {
        ++b;
        if (b == 60) {
            b = 0;
            ++a;
            if (a == 24) {
                a = 0;
            }
        }
        string s;
        s += a / 10 + '0';
        s += a % 10 + '0';
        s += ':';
        s += b / 10 + '0';
        s += b % 10 + '0';
        if (s[0] == s[4] && s[1] == s[3]) {
            cout << s << endl;
            return 0;
        }
    }
    return 0;
}