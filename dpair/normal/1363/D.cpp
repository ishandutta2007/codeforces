// 
#pragma GCC optimize(2, 3, "Ofast")
#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,s,t) for(int i=(s),i##END=(t);i<=i##END;++i)
#define per(i,t,s) for(int i=(t),i##END=(s);i>=i##END;--i)
#define REP(i,s,t) for(int i=(s),i##END=(t);i<i##END;++i)
#define PER(i,t,s) for(int i=(t),i##END=(s);i>i##END;--i)

/* My Code begins here */

int n, m;

inline int ask(int l, int r) {
    printf("? %d", r - l + 1);
    rep(i, l, r) printf(" %d", i);
    printf("\n"); fflush(stdout);
    int x; scanf("%d", &x); return x;
}

#include <vector>
std::vector < int > v[1005];
bool vis[1005];
inline void work() {
    scanf("%d%d", &n, &m);
    rep(i, 1, m) {
        v[i].clear(); int k; scanf("%d", &k);
        while(k --) {
            int x; scanf("%d", &x);
            v[i].push_back(x);
        }
    }
    int t = ask(1, n);
    int l = 1, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(ask(l, mid) == t) r = mid;
        else l = mid + 1;
    }

    int id = 0;
    rep(i, 1, m) {
        bool ck = 0;
        for (auto it : v[i]) if(it == l) { ck = 1; break; }
        if(ck) { id = i; break; }
    }

    int ans = 0;
    if(id) {
        memset(vis, 0, sizeof(vis));
        for (auto it : v[id]) vis[it] = 1;
        std::vector < int > ak;
        rep(i, 1, n) if(!vis[i]) ak.push_back(i);
        printf("? %lu", ak.size());
        for (auto it : ak) printf(" %d", it);
        printf("\n"); fflush(stdout); scanf("%d", &ans);
    }

    printf("!");
    rep(i, 1, m) {
        if(i == id) printf(" %d", ans);
        else printf(" %d", t);
    }
    printf("\n"); fflush(stdout);

    char tmp[15];
    scanf("%s", tmp);
}

signed main() {
    int T; scanf("%d", &T);
    while(T --) work();
}
/*






*/