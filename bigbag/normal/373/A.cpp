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

const int max_n = 5, inf = 111111111;

int k;
map<int, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; ++j) {
            if (s[j] != '.') {
                ++m[s[j] - '0'];
            }
        }
    }
    k *= 2;
    for (int i = 1; i <= 9; ++i) {
        if (m[i] > k) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}