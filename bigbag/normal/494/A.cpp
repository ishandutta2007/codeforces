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

const int max_n = 111111, inf = 1111111111;

int x, y;
string s;
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int bal = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            ++x;
            ++bal;
        }
        if (s[i] == ')') {
            ++y;
            --bal;
        }
        if (bal < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    int poz = -1;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '#') {
            poz = i;
        }
    }
    if (x <= y) {
        cout << -1 << endl;
        return 0;
    }
    bal = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            ++bal;
        }
        if (s[i] == ')') {
            --bal;
        }
        if (s[i] == '#') {
            if (i == poz) {
                if (y == x) {
                    cout << -1 << endl;
                    return 0;
                }
                bal -= x - y;
                ans.push_back(x - y);
            } else {
                --bal;
                --x;
                ans.push_back(1);
            }
        }
        if (bal < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}