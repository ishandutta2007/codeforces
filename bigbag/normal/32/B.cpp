#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222, inf = 111111111;

int n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    gets(s);
    int l = strlen(s);
    for (int i = 0; i < l; ++i) {
        if (s[i] == '.') {
            cout << 0;
        } else {
            if (s[i] == '-' && s[i + 1] == '.') {
                cout << 1;
            } else {
                cout << 2;
            }
            ++i;
        }
    }
    return 0;
}