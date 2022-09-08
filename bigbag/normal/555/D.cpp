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

const int max_n = 222222, inf = 2111111111;

int n, m, poz[max_n];
pair<int, int> p[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    p[n] = make_pair(inf, n);
    ++n;
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        poz[p[i].second] = i;
    }
    while (m--) {
        int num, len;
        scanf("%d%d", &num, &len);
        --num;
        num = poz[num];
        int x = p[num].first;
        while (true) {
            pair<int, int> q = *upper_bound(p, p + n, make_pair(x + len, inf));
            //cout << x << " " << len << "     " << q.second << endl;
            q = p[poz[q.second] - 1];
            int dx = q.first - x;
            if (dx) {
                len -= dx;
                x = q.first;
                continue;
            }
            pair<int, int> q2 = *lower_bound(p, p + n, make_pair(x - len, -1));
            dx = x - q2.first;
            if (dx == 0) {
                printf("%d\n", q2.second + 1);
                break;
            }
            if (dx * 2 >= len) {
                len -= dx;
                x = q2.first;
                continue;
            }
            int k = len / dx;
            len %= dx;
            if (k % 2 == 1) {
                x = q2.first;
            }
        }
    }
    return 0;
}