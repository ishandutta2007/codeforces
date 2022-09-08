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

int n, s, a[max_n], b[max_n];
vector<pair<int, int> > v1, v2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) {
        char c;
        int p, q;
        scanf("\n%c%d%d", &c, &p, &q);
        if (c == 'B') {
            a[p] += q;
        } else {
            b[p] += q;
        }
    }
    for (int i = max_n - 1; i >= 0; --i) {
        if (a[i]) {
            v1.push_back(make_pair(i, a[i]));
        }
        if (b[i]) {
            v2.push_back(make_pair(i, b[i]));
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    reverse(v1.begin(), v1.end());
    for (int i = min(s, (int) v2.size()) - 1; i >= 0; --i) {
        printf("S %d %d\n", v2[i].first, v2[i].second);
    }
    for (int i = 0; i < min(s, (int) v1.size()); ++i) {
        printf("B %d %d\n", v1[i].first, v1[i].second);
    }
    return 0;
}