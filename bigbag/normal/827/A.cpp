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

const int max_n = 2011111, inf = 1011111111;

int l, n, k, pos;
char s[max_n], ans[max_n];
set<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        q.insert(i);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", s, &k);
        int len = strlen(s);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &pos);
            --pos;
            set<int>::iterator it = q.lower_bound(pos);
            set<int>::iterator ft = it;
            while (true) {
                int mn = *it;
                if (mn < pos + len) {
                    ans[mn] = s[mn - pos];
                    l = max(l, mn);
                } else {
                    break;
                }
                ++it;
            }
            q.erase(ft, it);
        }
    }
    ++l;
    for (int i = 0; i < l; ++i) {
        if (ans[i] == 0) {
            ans[i] = 'a';
        }
    }
    printf("%s\n", ans);
    return 0;
}