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

const int max_n = 505555, inf = 1011111111;

int n, ans;
string s[max_n];
char A[max_n];

string read() {
    scanf("%s", A);
    return A;
}

void upd(int num, int len) {
    ans += s[num].length() - len;
    s[num] = s[num].substr(0, len);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        s[i] = read();
    }
    for (int i = n - 2; i >= 0; --i) {
        int pos = 0;
        while (pos < s[i].length() && pos < s[i + 1].length() && s[i][pos] == s[i + 1][pos]) {
            ++pos;
        }
        if (pos == s[i].length()) {
        } else if (pos == s[i + 1].length()) {
            upd(i, pos);
        } else if (s[i][pos] > s[i + 1][pos]) {
            upd(i, pos);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", s[i].c_str());
    }
    return 0;
}