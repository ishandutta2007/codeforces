#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
typedef unsigned long long uint64;
static const int MAXN = 3e5 + 4;

int n, m;
std::vector<int> e[MAXN];
uint64 e_hash[MAXN];
std::map<uint64, std::vector<int>> bucket;
std::map<uint64, std::set<uint64>> e_new;
int label[MAXN];

inline uint64 vector_hash(const std::vector<int> &v) {
    uint64 ret = 0;
    for (int x : v) ret = ret * 1000000007 + x;
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        e[i].push_back(i);
        std::sort(e[i].begin(), e[i].end());
        e_hash[i] = vector_hash(e[i]);
        bucket[e_hash[i]].push_back(i);
    }

    for (int u = 0; u < n; ++u) {
        auto &list = e_new[e_hash[u]];
        for (int v : e[u]) if (e_hash[u] != e_hash[v])
            list.insert(e_hash[v]);
    }

    bool is_cycle = true;
    uint64 endpoint;
    if (e_new.size() == 1u) {
        is_cycle = false;
        endpoint = e_new.begin()->first;
    } else for (auto kv : e_new) {
        if (kv.second.size() > 2u) { puts("NO"); return 0; }
        else if (kv.second.size() == 1u) is_cycle = false, endpoint = kv.first;
    }

    if (is_cycle) puts("NO");
    else {
        puts("YES");
        for (int v : bucket[endpoint]) label[v] = 1;
        uint64 last = endpoint, next;
        endpoint = *(e_new[endpoint].begin());
        for (int l = 2; endpoint != -1; endpoint = next, ++l) {
            for (int v : bucket[endpoint]) label[v] = l;
            next = -1;
            for (uint64 v : e_new[endpoint]) if (v != last) { next = v; break; }
            last = endpoint;
        }
        for (int i = 0; i < n; ++i) printf("%d%c", label[i], i == n - 1 ? '\n' : ' ');
    }

    return 0;
}