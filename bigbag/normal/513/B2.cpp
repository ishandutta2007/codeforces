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

const int max_n = 60, inf = 1111111111;

long long n, m;
long long pw[max_n];

void get_ans(int n, int sd) {
    if (n == 0) {
        return;
    }
    if (m <= pw[n - 2]) {
        cout << 1 + sd << " ";
        get_ans(n - 1, sd + 1);
    } else {
        m -= pw[n - 2];
        get_ans(n - 1, sd + 1);
        cout << 1 + sd << " ";
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = pw[i - 1] * 2;
    }
    get_ans(n, 0);
    return 0;
}