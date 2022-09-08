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

int n, k;
char s[max_n];
vector<int> v;

bool check(int x) {
    int poz1 = 0, poz2 = 0, res = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (v[i] - v[poz1] > x) {
            ++poz1;
        }
        while (poz2 + 1 < v.size() && v[poz2 + 1] - v[i] <= x) {
            ++poz2;
        }
        res = max(res, poz2 - poz1 + 1);
    }
    return res >= k + 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            v.push_back(i);
        }
    }
    int l = 0, r = max_n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}