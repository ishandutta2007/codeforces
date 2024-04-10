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

const int max_n = 333, inf = 1111111111;

int n, q, used[max_n];
string s[max_n];

string merge(string a, string b) {
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < a.length(); ++i) {
            string q = "";
            q = a.substr(0, i);
            q += b;
            if (q.length() < a.length()) {
                q += a.substr(q.length());
            }
            if (q.substr(0, a.length()) == a) {
                return q;
            }
        }
        swap(a, b);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    while (n > 1) {
        int a = -1, b = -1;
        for (int i = 0; i < n; ++i) {
            ++q;
            for (int j = 0; j < s[i].length(); ++j) {
                used[s[i][j]] = q;
            }
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                int f = 0;
                for (int k = 0; k < s[j].length(); ++k) {
                    if (used[s[j][k]] == q) {
                        f = 1;
                        break;
                    }
                }
                if (f == 1) {
                    a = i;
                    b = j;
                    break;
                }
            }
            if (a != -1) {
                break;
            }
        }
        if (a != -1) {
            if (a > b) {
                swap(a, b);
            }
            s[a] = merge(s[a], s[b]);
            --n;
            for (int j = b; j < n; ++j) {
                s[j] = s[j + 1];
            }
        } else {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}