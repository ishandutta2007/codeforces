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

const int max_n = 1111111, inf = 1011111111;

int str_to_int(string s) {
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
        x = x * 10 + s[i] - '0';
    }
    return x;
}

int h;
string s;
vector<string> ans[max_n];

void read() {
    char a[max_n];
    scanf("%s", a);
    s = a;
}

int rec(int pos, int d) {
    string name = "";
    while (s[pos] != ',') {
        name += s[pos];
        ++pos;
    }
    if (0) {
        for (int i = 1; i < d; ++i) {
            cout << " ";
        }
        cout << name << endl;
    }
    h = max(h, d);
    ans[d].push_back(name);
    ++pos;
    int cnt = 0;
    while (pos < s.length() && '0' <= s[pos] && s[pos] <= '9') {
        cnt *= 10;
        cnt += s[pos] - '0';
        ++pos;
    }
    ++pos;
    for (int i = 0; i < cnt; ++i) {
        pos = rec(pos, d + 1);
    }
    return pos;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    read();
    int pos = 0;
    while (pos < s.length()) {
        pos = rec(pos, 1);
    }
    if (pos != s.length() + 1) {
        return 228;
    }
    printf("%d\n", h);
    for (int i = 1; i <= h; ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            printf("%s ", ans[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}