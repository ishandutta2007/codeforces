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

const int max_n = 1111, inf = 1111111111;

int n;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (f) {
            continue;
        }
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = s[i][1] = '+';
            f = 1;
        } else if (s[i][3] == 'O' && s[i][4] == 'O') {
            s[i][3] = s[i][4] = '+';
            f = 1;
        }
    }
    if (f) {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << s[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}