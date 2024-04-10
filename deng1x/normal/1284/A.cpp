#include <bits/stdc++.h>
#include <cstdio>
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

const int max_N = 30;

int n, m;
std::string s[max_N];
std::string t[max_N];

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> t[i];
    }
    int q;
    std::cin >> q;
    while (q--) {
        int y;
        std::cin >> y;
        --y;
        int a = y % n, b = y % m;
        std::cout << s[a] << t[b] << std::endl;
    }
    return 0;
}