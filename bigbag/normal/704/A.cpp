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

const int max_n = 303333, inf = 1111111111;

int n, test, cnt, tm[max_n];
set<int> q[max_n];
set<pair<int, int> > all;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &test);
    for (int i = 0; i < test; ++i) {
        int tp, x;
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d", &x);
            tm[i] = cnt;
            ++cnt;
            q[x].insert(i);
            all.insert(make_pair(i, x));
        } else if (tp == 2) {
            scanf("%d", &x);
            for (set<int>::iterator it = q[x].begin(); it != q[x].end(); ++it) {
                int t = *it;
                all.erase(make_pair(t, x));
            }
            q[x].clear();
        } else {
            scanf("%d", &x);
            while (all.size()) {
                pair<int, int> p = *all.begin();
                if (tm[p.first] < x) {
                    all.erase(p);
                    q[p.second].erase(p.first);
                } else {
                    break;
                }
            }
        }
        printf("%d\n", all.size());
    }
    return 0;
}