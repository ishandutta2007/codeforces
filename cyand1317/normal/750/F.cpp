#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

std::vector<int> neigh[(1 << 7) + 20];

inline void get_neighbours(int u) {
    if (neigh[u].size() > 0) return;
    printf("? %d\n", u); fflush(stdout);
    int k, v;
    scanf("%d", &k);
    if (k == 0) exit(0);
    for (int i = 0; i < k; ++i) {
        scanf("%d", &v); neigh[u].push_back(v);
    }
}
inline int exclude_neighbours(int u, int v, int w) {
    for (int i = 0; i < (int)neigh[u].size(); ++i)
        if (neigh[u][i] != v && neigh[u][i] != w) return neigh[u][i];
    return -1;
}
inline int exclude_neighbours(int u, int v) {
    for (int i = 0; i < (int)neigh[u].size(); ++i)
        if (neigh[u][i] != v) return neigh[u][i];
    return -1;
}

inline void find_chain(std::vector<int> &v, int u, int b1 = -1, int b2 = -1) {
    v.push_back(u);
    get_neighbours(u);
    if (neigh[u].size() == 2) return;
    for (int i = 0; i < (int)neigh[u].size(); ++i) if (b1 != neigh[u][i] && b2 != neigh[u][i]) {
        find_chain(v, neigh[u][i], b1, u); break;
    }
}

void work()
{
    int h;
    scanf("%d", &h);
    if (h == 0) exit(0);
    for (int i = 0; i <= (1 << h); ++i) neigh[i].clear();

    int ans, depth, half;
    std::vector<int> c, d;
    find_chain(c, 1);
    if (neigh[c.back()].size() == 2) { ans = c.back(); goto print_answer; }
    find_chain(d, 1, c[1]);
    if (neigh[d.back()].size() == 2) { ans = d.back(); goto print_answer; }
    std::reverse(c.begin(), c.end());
    for (int i = 1; i < (int)d.size(); ++i) c.push_back(d[i]);
    //for (int i = 0; i < (int)c.size(); ++i) printf("%d%c", c[i], i == (int)c.size() - 1 ? '\n' : ' ');
    depth = h - (int)c.size() / 2;
    //printf("%d\n", depth);
    while (depth > 4) {
        //printf("> Depth = %d / Centre = %d\n", depth, c[(int)c.size() / 2]);
        std::vector<int> e;
        for (int i = 0; i < (int)c.size() / 2; ++i) e.push_back(c[i]);
        find_chain(e, c[(int)c.size() / 2], c[(int)c.size() / 2 - 1], c[(int)c.size() / 2 + 1]);
        //printf("> Length = %d\n", (int)e.size());
        if (neigh[e.back()].size() == 2) { ans = e.back(); goto print_answer; }
        c = e;
        depth = h - (int)c.size() / 2;
    }
    half = (int)c.size() / 2;
    //printf(":: Depth = %d\n", depth);
    if (depth == 1) ans = c[half];
    else if (depth == 2) ans = exclude_neighbours(c[half], c[half - 1], c[half + 1]);
    else if (depth == 3) {
        int d3 = exclude_neighbours(c[half], c[half - 1], c[half + 1]);
        get_neighbours(d3);
        int d21 = exclude_neighbours(d3, c[half]), d22 = exclude_neighbours(d3, c[half], d21);
        get_neighbours(d21), get_neighbours(d22);
        if (neigh[d21].size() == 2) ans = d21;
        else if (neigh[d22].size() == 2) ans = d22;
    } else if (depth == 4) {
        int d3 = exclude_neighbours(c[half], c[half - 1], c[half + 1]);
        get_neighbours(d3);
        int d21 = exclude_neighbours(d3, c[half]), d22 = exclude_neighbours(d3, c[half], d21);
        get_neighbours(d21), get_neighbours(d22);
        int d11 = exclude_neighbours(d21, d3), d12 = exclude_neighbours(d21, d3, d11),
            d13 = exclude_neighbours(d22, d3), d14 = exclude_neighbours(d22, d3, d13);
        get_neighbours(d11), get_neighbours(d12), get_neighbours(d13);
        if (neigh[d11].size() == 2) ans = d11;
        else if (neigh[d12].size() == 2) ans = d12;
        else if (neigh[d13].size() == 2) ans = d13;
        else ans = d14;
    /*} else {    // depth == 5
        int d4 = exclude_neighbours(c[half], c[half - 1], c[half + 1]);
        get_neighbours(d4);
        int d31 = exclude_neighbours(d4, c[half]), d32 = exclude_neighbours(d4, c[half], d31);
        get_neighbours(d31), get_neighbours(d32);
        int d21 = exclude_neighbours(d31, d4), d22 = exclude_neighbours(d21, d4, d21),
            d23 = exclude_neighbours(d32, d4), d24 = exclude_neighbours(d22, d4, d23);
        get_neighbours(d21), get_neighbours(d22), get_neighbours(d23), get_neighbours(d24);
        int d11 = exclude_neighbours(d21, d31), d12 = exclude_neighbours(d21, d31, d11),
            d13 = exclude_neighbours(d22, d31), d14 = exclude_neighbours(d22, d31, d13),
            d15 = exclude_neighbours(d23, d32), d16 = exclude_neighbours(d23, d32, d15),
            d17 = exclude_neighbours(d24, d32), d18 = exclude_neighbours(d24, d32, d17);
        get_neighbours(d11), get_neighbours(d12), get_neighbours(d13), get_neighbours(d14);
        get_neighbours(d15), get_neighbours(d16), get_neighbours(d17), get_neighbours(d18);
        if (neigh[d11].size() == 2) ans = d11;
        else if (neigh[d12].size() == 2) ans = d12;
        else if (neigh[d13].size() == 2) ans = d13;
        else if (neigh[d14].size() == 2) ans = d14;
        else if (neigh[d15].size() == 2) ans = d15;
        else if (neigh[d16].size() == 2) ans = d16;
        else if (neigh[d17].size() == 2) ans = d17;
        else if (neigh[d18].size() == 2) ans = d18;*/
    }
print_answer:
    printf("! %d\n", ans); fflush(stdout);
}

int main()
{
    int T; scanf("%d", &T);
    do work(); while (--T);
    return 0;
}