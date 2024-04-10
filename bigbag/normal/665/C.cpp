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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i + 1 < s.length(); ++i) {
        if (s[i] == s[i + 1]) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (s[i] == c) {
                    continue;
                }
                if (i + 2 == s.length() || s[i + 2] != c) {
                    s[i + 1] = c;
                    break;
                }
            }
        }
    }
    cout << s << endl;
    return 0;
}