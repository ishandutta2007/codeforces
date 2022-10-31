#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


struct Candy{
    int t, h, m;
    bool operator<(const Candy &rhs) const {
        return h < rhs.h;
    }
} candy[2010];

struct cmp {
    bool operator()(Candy a, Candy b) {
        return a.m < b.m;
    }
};

int n, x;

int solve() {
    priority_queue<Candy, vector<Candy>, cmp> q[2];
    int ret = 0, h = x, stat = 0;
    for(int i = 0; i < n; ++i) {
        if(candy[i].h <= h) {
            q[candy[i].t].push(candy[i]);
        }
        else {
            --i;
            if(q[stat].size() == 0) {
                break;
            }
            Candy c = q[stat].top();
            q[stat].pop();
            ret++;
            h += c.m;
            stat ^= 1;
        }
    }
    while(q[stat].size()) {
        q[stat].pop();
        ret++;
        stat ^= 1;
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        candy[i] = (Candy){a, b, c};
    }
    sort(candy, candy + n);
    int ans = solve();
    for(int i = 0; i < n; ++i)
        candy[i].t ^= 1;
    ans = max(ans, solve());
    printf("%d\n", ans);
    return 0;
}