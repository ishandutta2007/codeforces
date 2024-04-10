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

long long n, ans = 1;
string s, t;
char q[10];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    s = "#" + s;
    t += s[1];
    t += s[3];
    t += s[5];
    t += s[4];
    t += s[2];
    n = atoi(t.c_str());
    for (int i = 0; i < 5; ++i) {
        ans = (ans * n) % 100000;
    }
    s = "";
    while (ans) {
        s += ans % 10 + '0';
        ans /= 10;
    }
    reverse(s.begin(), s.end());
    for (int i = s.length(); i < 5; ++i) {
        cout << 0;
    }
    cout << s << endl;
    return 0;
}