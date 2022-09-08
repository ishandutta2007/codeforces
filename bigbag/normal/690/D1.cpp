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

int n, m, ans;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
    }
    for (int i = 0; i < m; ++i) {
        if (s[i] == 'B') {
            while (i < m && s[i] == 'B') {
                ++i;
            }
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}