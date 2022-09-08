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

const int max_n = 2111111, inf = 1111111111;

int n, ans[max_n];
long long x, y;
vector<pair<long long, int> > v;

void solve(int a) {
    --a;
    a %= v.size();
    if (ans[a] == 3) {
        printf("Both\n");
    } else if (ans[a] == 2) {
        printf("Vova\n");
    } else if (ans[a] == 1) {
        printf("Vanya\n");
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= y; ++i) {
        v.push_back(make_pair(x * i, 2));
    }
    for (int i = 1; i <= x; ++i) {
        v.push_back(make_pair(y * i, 1));
    }
    sort(v.begin(), v.end());
    ans[0] = v[0].second;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1].first == v[i].first) {
            ans[i] = ans[i - 1] = 3;
        } else {
            ans[i] = v[i].second;
        }
    }
    while (n--) {
        int a;
        scanf("%d", &a);
        solve(a);
    }
    return 0;
}