#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
  
typedef long long ll;

const int max_n = 1e5;
const int max_m = 3e5;
const int max_k = 1e5;

int n, m, k;

ll dist[max_n];

int q[max_n + 1];
int q_sz;

int ans;

int id_in_q[max_n];

pair<ll, int> tr[max_k];

void go_down(int id)
{
    while (id * 2 <= q_sz) {
        int nid = id;
        if (dist[q[id * 2]] < dist[q[nid]]) nid = id * 2;
        if (id * 2 + 1 <= q_sz && dist[q[id * 2 + 1]] < dist[q[nid]]) nid = id * 2 + 1;
        if (id == nid) break;
        swap(q[id], q[nid]);
        swap(id, nid);
        id_in_q[q[id]] = id;
        id_in_q[q[nid]] = nid;
    }
}

void go_up(int id)
{
    while (id > 1) {
        int nid = id >> 1;
        if (dist[q[id]] < dist[q[nid]]) {
            swap(q[id], q[nid]);
            swap(id, nid);
            id_in_q[q[id]] = id;
            id_in_q[q[nid]] = nid;
        } else {
            break;
        }
    }
}

void build_queue()
{
    q_sz = n;
    for (int i = 1; i <= n; ++i) {
        q[i] = i - 1;
        id_in_q[i - 1] = i;
    }
    for (int i = n; i >= 1; --i) {
        go_down(i);
    }
}

int get_top()
{
    return q[1];
}

void pop_top()
{
    id_in_q[q[1]] = -1;
    id_in_q[q[q_sz]] = 1;
    swap(q[1], q[q_sz]);
    --q_sz;
    go_down(1);
}

bool q_empty()
{
    return q_sz == 0;
}

int hd[max_n];
int nx[2 * max_m];
int g[2 * max_m];
ll w[2 * max_m];
int sz;

void init_list()
{
    sz = 0;
    for (int i = 0; i < n; ++i)
        hd[i] = -1;
}

void add_to_list(int v1, int v2, ll cw)
{
    nx[sz] = hd[v1];
    g[sz] = v2;
    w[sz] = cw;
    hd[v1] = sz;
    ++sz;
}

const ll inf = 1e18;

void djkstra()
{
    for (int i = 1; i < n; ++i)
        dist[i] = inf;
    dist[0] = 0;
    build_queue();
    int ptr = 0;
    while (!q_empty() && ptr < k) {
        if (id_in_q[tr[ptr].second] == -1) {
            ++ans;
            ++ptr;
            continue;
        }
        int v = get_top();
        if (dist[v] > tr[ptr].first) {
            dist[tr[ptr].second] = tr[ptr].first;
            go_up(id_in_q[tr[ptr].second]);
            ++ptr;
        } else {
            pop_top();
            for (int i = hd[v]; i != -1; i = nx[i]) {
                int u = g[i];
                int cw = w[i];
                if (cw + dist[v] < dist[u]) {
                    dist[u] = cw + dist[v];
                    go_up(id_in_q[u]);
                }
            }
        }
    }
    ans += k - ptr;
}

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
  
    scanf("%d%d%d", &n, &m, &k);
    
    init_list();
    for (int i = 0; i < m; ++i) {
        int v1, v2, cw;
        scanf("%d%d%d", &v1, &v2, &cw);
        --v1; --v2;
        add_to_list(v1, v2, cw);
        add_to_list(v2, v1, cw);
    }
    
    for (int i = 0; i < k; ++i) {
        int to, cost;
        scanf("%d%d", &to, &cost);
        --to;
        tr[i].first = cost;
        tr[i].second = to;
    }
    
    sort(tr, tr + k);
    
    ans = 0;
    djkstra();

    printf("%d\n", ans);

    return 0;
}