#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

int ans[800005];

struct Edge {
    int v, way, no;
    Edge(int _v = 0, int _way = 0, int _no = 0): v(_v), way(_way), no(_no) {}
};

struct Element {
    int v, deg;
    Element(int _v = 0, int _deg = 0) : v(_v), deg(_deg) {}
    bool operator<(const Element &cmp) const {
        return deg > cmp.deg;
    }
};

std::priority_queue<Element> Q;

int N, M, K;

std::vector<Edge> graph[400005];
int now[400005];
int d[400005];
bool vst[400005];

void DFS(int v, int from) {
    //printf("now %d\n", v);
    if (d[v] == 1 && from != -1) return;
    for ( ; now[v] < graph[v].size(); ) {
        Edge tmp = graph[v][now[v]];
        ++now[v];
        if (tmp.v == from || ans[tmp.no] != -1) continue;
        //printf("%d -- %d\n", v, tmp.v);
        DFS(tmp.v, v);
        Q.push(Element(v, --d[v]));
        Q.push(Element(tmp.v, --d[tmp.v]));
        ans[tmp.no] = tmp.way;
        return;
    } 
    return;
}

int killCycle(int v, int from) {
    //printf("kill %d\n", v);
    if (vst[v]) return v;
    vst[v] = true;
    for (; now[v] < graph[v].size(); ) {
        Edge tmp = graph[v][now[v]];
        ++now[v];
        if (tmp.no == from || ans[tmp.no] != -1) continue;
        //printf("go %d %d\n", v, tmp.v);
        int ret = killCycle(tmp.v, tmp.no);
        if (ret != -1) {
            //printf("%d = %d\n", v, tmp.v);
            ans[tmp.no] = tmp.way;
            d[v] -= 2;
            if (ret != v) {
                vst[v] = false;
                return ret;
            }
        }
    } 
    return -1;
}

int main() {
    int T=1;
    while (T--) {
        N=400000;
        scanf("%d", &M);
        for (int i = 0; i < N; ++i) {
            graph[i].clear();
            now[i] = 0;
            vst[i] = false;
        }
        for (int i = 0; i < M; ++i) {
            ans[i] = -1;
            int a, b;
            scanf("%d%d", &a, &b);
            a--;b--;b+=200000;
            graph[a].push_back(Edge(b, 1, i));
            graph[b].push_back(Edge(a, 0, i));
            ++d[a]; ++d[b];
        }
        //puts("kill cycle");
        for (int i = 0; i < N; ++i) {
            //printf("orzzzzzzzzzzzzzzzzzzzzzzzzzzzzz: %d\n", i);
            killCycle(i, -1);
        }
        //puts("DFS");
        for (int i = 0; i < N; ++i) {
            Q.push(Element(i, d[i]));
            now[i] = 0;
        }
        while (!Q.empty()) {
            Element tmp = Q.top();
            Q.pop();
            if (tmp.deg != d[tmp.v]) continue;
            if (tmp.deg == 1) {
                DFS(tmp.v, -1);
            }
        }
        for (int i = 0; i < M; ++i) 
            printf("%c", ans[i]?'b':'r');
        putchar('\n');
    }
}