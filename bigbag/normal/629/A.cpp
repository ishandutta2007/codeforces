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

const int max_n = 111, inf = 1111111111;

int n, ans;
string s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'C') {
                ++x;
            }
        }
        ans += (x * (x - 1)) / 2;
    }
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == 'C') {
                ++x;
            }
        }
        ans += (x * (x - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}