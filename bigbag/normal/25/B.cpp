#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d\n", &n);
    gets(s);
    if (n == 2 || n == 3) {
        cout << s << endl;
        return 0;
    }
    if (n % 3 == 0) {
        for (int i = 0; i + 2 < n; i += 3) {
            cout << s[i] << s[i + 1] << s[i + 2];
            if (i + 3 < n) {
                cout << "-";
            }
        }
    }
    if (n % 3 == 1) {
        cout << s[0] << s[1] << "-" << s[2] << s[3];
        if (n > 4) {
            cout << "-";
        }
        for (int i = 4; i + 2 < n; i += 3) {
            cout << s[i] << s[i + 1] << s[i + 2];
            if (i + 3 < n) {
                cout << "-";
            }
        }
    }
    if (n % 3 == 2) {
        cout << s[0] << s[1] << "-";
        for (int i = 2; i + 2 < n; i += 3) {
            cout << s[i] << s[i + 1] << s[i + 2];
            if (i + 3 < n) {
                cout << "-";
            }
        }
    }
    return 0;
}