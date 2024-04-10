#include <bits/stdc++.h>
using namespace std;

struct E {
    int a, b, c;
};
bool cmp(E a, E b) { return a.c < b.c; }
E e[300010];
int n, m, d[300010]={}, t[300010]={};

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0, a, b, c; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        e[i] = (E){a, b, c};
    }
    sort(e, e + m, cmp);
    int ans = 0;

    for(int i = 0; i < m; ) {

        int j = i;
        while(j + 1 < m && e[i].c == e[j+1].c) j++;

        for(int k = i; k <= j; ++k) t[e[k].b] = max(t[e[k].b], d[e[k].a] + 1);
        for(int k = i; k <= j; ++k) {
            d[e[k].b] = max(t[e[k].b], d[e[k].b]);
            t[e[k].b] = 0;
            ans = max(ans, d[e[k].b]);
        }

        i = j + 1;
    }

    printf("%d\n", ans);

    return 0;
}