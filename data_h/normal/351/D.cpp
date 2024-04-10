#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;
const int MaxV = 100000;
int n, q;
vector<pair<int, int> > query[N];

int h1[N], h2[N], next[N], pos[N], last[N], a[N];
int ans[N];

inline int lowbit(int x) {
    return x & (-x);
}

inline int ask(int h[], int pos) {
    int res = 0;
    for(int i = pos; i; i -= lowbit(i)) 
        res += h[i];
    return res;
}

inline int ins(int h[], int pos, int val, int bound = n) {
    for(int i = pos; i <= bound; i += lowbit(i)) 
        h[i] += val;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        query[l].push_back(make_pair(r, i));
    }
    for(int i = 1; i <= MaxV; i++)
        pos[i] = n + 1;
    last[n + 1] = n + 1;
    for(int i = n; i >= 1; i--) {
        next[i] = pos[a[i]];
        pos[a[i]] = i;
        last[i] = n + 1;
        if (next[i] <= n) {
            if (next[next[i]] > n || next[i] - i == next[next[i]] - next[i])
                last[i] = last[next[i]];
            else
                last[i] = next[next[i]];
        }
    }
    //for(int i = 1; i <= n; i++)
    //  printf("%d ", last[i]);
    //printf("\n");
    
    for(int i = n; i >= 1; i--) {
        ins(h1, i, 1);
        if (next[i] <= n)
            ins(h1, next[i], -1);
        ins(h2, i, 1);
        ins(h2, last[i], -1);
        if (next[i] <= n) {
            ins(h2, next[i], -1);
            ins(h2, last[next[i]], 1);
        }
        for(int j = 0; j < query[i].size(); j++) {
            int r = query[i][j].first, id = query[i][j].second;
            ans[id] = ask(h1, r) + (ask(h2, r) == 0);
        }
    }
    for(int i = 1; i <= q; i++)
        printf("%d\n", ans[i]);
    return 0;
}