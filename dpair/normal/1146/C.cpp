#include <cstdio>
#include <vector>

std::vector < int > v[2];
inline void work() {
    int n; scanf("%d", &n);
    int ans = 0; for(int i = 0;i < 9;++ i) {
        v[0].clear(); v[1].clear();
        for (int j = 1;j <= n;++ j) v[j >> i & 1].push_back(j);
        if(v[0].empty() || v[1].empty()) break;
        printf("%lu %lu", v[0].size(), v[1].size());
        for (auto it : v[0]) printf(" %d", it);
        for (auto it : v[1]) printf(" %d", it);
        printf("\n"); fflush(stdout);
        int x; scanf("%d", &x); if(ans < x) ans = x;
    }
    printf("-1 %d\n", ans); fflush(stdout);
}

int main() {
    int T; scanf("%d", &T);
    while(T --) work();
}