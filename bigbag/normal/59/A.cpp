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
    int c1 = 0, c2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            ++c1;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ++c2;
        }
    }
    if (c1 >= c2) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                printf("%c", s[i] - 'A' + 'a');
            } else {
                printf("%c", s[i]);
            }
        }
    } else {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                printf("%c", s[i] - 'a' + 'A');
            } else {
                printf("%c", s[i]);
            }
        }
    }
    return 0;
}