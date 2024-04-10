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

const int max_n = 11111, inf = 1111111111;

int n, m;
vector<pair<int, string> > v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (n--) {
        char s[11];
        int tp, x;
        scanf("%s%d%d", s, &tp, &x);
        v[tp].push_back(make_pair(x, s));
    }
    for (int i = 1; i <= m; ++i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        if (v[i].size() > 2 && v[i][1].first == v[i][2].first) {
            printf("?\n");
        } else {
            printf("%s %s\n", v[i][0].second.c_str(), v[i][1].second.c_str());
        }
    }
    return 0;
}