#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n, T;
vector<vector<int> >g;
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        vector<int>d;
        g.clear();
        for (int i = 1;i <= n; i ++) {
            int x;
            scanf("%d", &x);
            if (i == 1) d.push_back(x);
            else {
                if (d[d.size() - 1] < x)
                    d.push_back(x);
                else {
                    g.push_back(d);
                    d.resize(1);
                    d[0] = x;
                }
            }
        }
        g.push_back(d);
        bool sig = 1;
        if (g.size() == 1) {
            sig = 1;
        } else {
            if (g[0][0] < g[g.size() - 1][g[g.size() - 1].size() - 1])
                sig = 1;
            else
                sig = 0;
        }
        if (sig)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}