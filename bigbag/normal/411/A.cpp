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

string s;

bool good(string s) {
    if (s.length() < 5) {
        return false;
    }
    int f1 = 0, f2 = 0, f3 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            f1 = 1;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            f2 = 1;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            f3 = 1;
        }
    }
    return f1 + f2 + f3 == 3;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    if (good(s)) {
        cout << "Correct" << endl;
    } else {
        cout << "Too weak" << endl;
    }
    return 0;
}