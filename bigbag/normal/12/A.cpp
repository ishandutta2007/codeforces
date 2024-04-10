#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[5][5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        gets(s[i]);
    }
    if (s[0][0] == s[2][2] && s[0][1] == s[2][1] && s[0][2] == s[2][0] && s[1][0] == s[1][2]) cout << "YES";
    else cout << "NO";
    return 0;
}