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

const int max_n = 222222, inf = 1111111111;

int n, k, q, a[max_n];
set<pair<int, int> > s1;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &k, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    while (q--) {
        int tp, x;
        scanf("%d%d", &tp, &x);
        --x;
        if (tp == 1) {
            s1.insert(make_pair(-a[x], x));
            if (s1.size() > k) {
                pair<int, int> p = *s1.rbegin();
                s1.erase(p);
            }
        } else {
            int f = 0;
            for (set<pair<int, int> >::iterator it = s1.begin(); it != s1.end(); ++it) {
                pair<int, int> p = *it;
                if (p.second == x) {
                    f = 1;
                }
            }
            if (f) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}