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

const int max_n = 1, inf = 1111111111;

string s;
int ans;
vector<char> c;

int tp(char c) {
    if (c == '<' || c == '{' || c == '(' || c == '[') {
        return 1;
    }
    return 2;
}

int num(char c) {
    if (c == '<' || c == '>') {
        return 1;
    }
    if (c == '{' || c == '}') {
        return 2;
    }
    if (c == '(' || c == ')') {
        return 3;
    }
    return 4;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (tp(s[i]) == 1) {
            c.push_back(s[i]);
        } else {
            if (c.size() == 0) {
                cout << "Impossible" << endl;
                return 0;
            }
            if (num(s[i]) != num(c.back())) {
                ++ans;
            }
            c.pop_back();
        }
    }
    if (c.size()) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}