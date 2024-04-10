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

const int max_n = 111, inf = 111111111;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    set <int> ans;
    for (int i = 0; i < n; ++i) {
        ans.clear();
        string s, q[22];
        cin >> s;
        for (int j = 1; j <= 12; ++j) {
            if (12 % j == 0) {
                for (int k = 0; k < 12 / j; ++k) {
                    q[k] = "";
                    for (int z = k * j; z < (k + 1) * j; ++z) {
                        q[k] += s[z];
                    }
                }
                for (int k = 0; k < j; ++k) {
                    int f = 0;
                    for (int z = 0; z < 12 / j; ++z) {
                        if (q[z][k] == 'O') {
                            f = 1;
                            break;
                        }
                    }
                    if (f == 0) {
                        ans.insert(j);
                        break;
                    }
                }
            }
        }
        cout << ans.size();
        if (ans.size() != 0) {
            cout << ' ';
        }
        while (ans.size() != 0) {
            int x = *ans.rbegin();
            ans.erase(x);
            cout << 12 / x << 'x' << x;
            if (ans.size() != 0) {
                cout << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}