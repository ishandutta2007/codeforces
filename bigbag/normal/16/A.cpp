#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, m;
char s[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i) {
        gets(s[i]);
        int l = strlen(s[i]);
        for (int j = 1; j < l; ++j) {
            if (s[i][j] != s[i][j - 1]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        if (s[i][0] == s[i - 1][0]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}