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

const int max_n = 2222, inf = 1011111111;

int n, used[max_n], a[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = n; i >= 1; --i) {
        int num = (i + 1) / 2;
        for (int j = 0; j < n; ++j) {
            if (used[j] == 0) {
                --num;
                if (num == 0) {
                    a[j] = n - i;
                    used[j] = 1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[a[i]];
    }
    cout << endl;
    return 0;
}