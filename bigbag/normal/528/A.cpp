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

int w, h, n;
char c, c1;
set<int> q[2];
multiset<int> s[2];

void proc(int t, int x) {
    set<int>::iterator it = q[t].lower_bound(x);
    int r = *it;
    if (r == x) {
        return;
    }
    --it;
    int l = *it;
    if (l == x) {
        return;
    }
    s[t].erase(s[t].find(r - l));
    s[t].insert(x - l);
    s[t].insert(r - x);
    q[t].insert(x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%c", &w, &h, &n, &c1);
    q[0].insert(0);
    q[0].insert(w);
    s[0].insert(w);
    q[1].insert(0);
    q[1].insert(h);
    s[1].insert(h);
    while (n--) {
        int x, t = 0;
        scanf("%c%c%d%c", &c, &c1, &x, &c1);
        if (c == 'H') {
            t = 1;
        }
        proc(t, x);
        int a = *s[0].rbegin();
        int b = *s[1].rbegin();
        printf("%I64d\n", 1LL * a * b);
    }
    return 0;
}