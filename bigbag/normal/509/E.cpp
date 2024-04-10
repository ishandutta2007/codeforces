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

const int max_n = 555555, inf = 1111111111;

int sum[max_n];
long long q[max_n];
double ans;
string s;

bool ok(char c) {
    return c == 'I' || c == 'E' || c == 'A' || c == 'O' || c == 'U' || c == 'Y';
}

int get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    sum[0] = ok(s[0]);
    for (int i = 1; i < s.length(); ++i) {
        sum[i] = sum[i - 1] + ok(s[i]);
    }
    q[1] = get_sum(0, s.length() - 1);
    int qwe = (s.length() + 1) / 2, l = 0, r = s.length() - 1;
    for (int i = 2; i <= s.length(); ++i) {
        ++l;
        --r;
        if (i > qwe) {
            q[i] = q[s.length() - i + 1];
        } else {
            q[i] = q[i - 1] + get_sum(l, r);
        }
    }
    for (int i = 1; i <= s.length(); ++i) {
        ans += q[i] / ((double) i);
    }
    printf("%.9lf\n", ans);
    return 0;
}