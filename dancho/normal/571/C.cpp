#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

int n, m;
vector<int> lic[1 << 20];
bool sat[1 << 20];

int val[1 << 20];

vector<pair<int, int> > g[1 << 20];

inline int ia(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

inline int si(int a) {
    if (a < 0) {
        return -1;
    }
    return 1;
}

void set_val(int v, int x) {
    // printf("SET VAL %d -> %d\n", v, x > 0);
    if (x < 0) {
        val[v] = 0;
    } else {
        val[v] = 1;
    }
}

void set_val(int v, int from, int to) {
    if (ia(lic[v][0]) == to) {
        set_val(v, lic[v][0]);
    } else if (ia(lic[v][1]) == to) {
        set_val(v, lic[v][1]);
    }
}

void set_sat(int v) {
    if (sat[v]) {
        return;
    }
    sat[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int u = g[v][i].first;
        if (!sat[u] && val[g[v][i].second] == -1) {
            set_sat(u);
            set_val(g[v][i].second, v, u);
        }
    }
}

int md[1 << 20];

void set_sat1(int v) {
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (val[g[v][i].second] == -1) {
            int u = g[v][i].first;
            set_val(g[v][i].second, -1, v);
            sat[v] = 1;
            md[u]--;
            if (!sat[u] && md[u] == 1) {
                set_sat1(u);
            }
            break;
        }
    }
}

int mdeg(int v) {
    int d = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        int k = g[v][i].second;
        if (val[k] == -1) {
            ++d;
        }
    }
    return d;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int v;
            scanf("%d", &v);
            lic[ia(v)].push_back(i * si(v));
        }
    }

    memset(sat, 0, sizeof(sat));
    memset(val, -1, sizeof(val));

    for (int i = 1; i <= m; ++i) {
        if (lic[i].size() == 2) {
            if (si(lic[i][0]) * si(lic[i][1]) == -1 && ia(lic[i][0]) != ia(lic[i][1])) {
                // printf("EDGE %d %d\n", ia(lic[i][0]), ia(lic[i][1]));
                g[ia(lic[i][0])].push_back(make_pair(ia(lic[i][1]), i));
                g[ia(lic[i][1])].push_back(make_pair(ia(lic[i][0]), i));
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        if (lic[i].size() == 0) {
            val[i] = 0;
        } else if (lic[i].size() == 1) {
            set_val(i, lic[i][0]);
            // printf("WTF %d %d -> %d\n", i, lic[i][0], val[
            set_sat(ia(lic[i][0]));
        } else {
            if (si(lic[i][0]) * si(lic[i][1]) == 1 || ia(lic[i][0]) == ia(lic[i][1])) {
                set_val(i, lic[i][0]);
                set_sat(ia(lic[i][0]));
                set_sat(ia(lic[i][1]));
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!sat[i]) {
            md[i] = mdeg(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (md[i] == 1 && !sat[i]) {
            // printf("SETTING bc degree %d\n", i);
            set_sat1(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!sat[i]) {
            set_sat1(i);
        }
    }

    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        if (!sat[i]) {
            ok = false;
        }
    }
    if (!ok) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= m; ++i) {
        if (val[i] == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
    return 0;
}