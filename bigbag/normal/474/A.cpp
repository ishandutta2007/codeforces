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

char c;
string a, s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> c >> s;
    a = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (int i = 0; i < s.length(); ++i) {
        int x = a.find(s[i]);
        if (c == 'L') {
            cout << a[x + 1];
        } else {
            cout << a[x - 1];
        }
    }
    return 0;
}