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

const int max_n = 222, inf = 1111111111;

int n, m;
char c[max_n][max_n];
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n - i - 1; ++i) {
        swap(s[i], s[n - i - 1]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            c[j][n - i - 1] = s[i][j];
        }
    }
    swap(n, m);
    for (int i = 0; i < n; ++i) {
        string q = "";
        for (int j = 0; j < m; ++j) {
            q += c[i][j];
            q += c[i][j];
        }
        cout << q << endl;
        cout << q << endl;
    }
    return 0;
}