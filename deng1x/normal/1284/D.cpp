//#include <bits/stdc++.h>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <cstring>

const int max_N = 100010;
using ll = long long;

int n;

bool solve(int *sa, int *ea, int *sb, int *eb) {
    std::multiset<int> set_left, set_right;
    std::vector<std::pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
        vec.emplace_back(sa[i], -i);
        vec.emplace_back(ea[i], i);
    }
    std::sort(vec.begin(), vec.end());
    for (auto &p : vec) {
        if (p.second > 0) {
            int i = p.second;
            set_left.erase(set_left.find(sb[i]));
            set_right.erase(set_right.find(eb[i]));
        } else {
            int i = -p.second;
            auto a = set_left.upper_bound(eb[i]);
            if (a != set_left.end()) return false;
            auto b = set_right.lower_bound(sb[i]);
            if (b != set_right.begin()) return false;

            set_left.insert(sb[i]);
            set_right.insert(eb[i]);
        }
    }

    return true;
}

int sa[max_N], ea[max_N], sb[max_N], eb[max_N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d%d%d", sa + i, ea + i, sb + i, eb + i);
    }

    if (!solve(sa, ea, sb, eb)) puts("NO");
    else if (!solve(sb, eb, sa, ea)) puts("NO");
    else puts("YES");
}