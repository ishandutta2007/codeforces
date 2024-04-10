#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, l, r, ans;
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        q.insert(make_pair(r, l));
    }
    int last = -1;
    while (q.size()) {
        pair<int, int> p = *q.begin();
        q.erase(p);
        l = p.second;
        r = p.first;
        if (l > last) {
            last = r;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}