#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <random>
using namespace std;

#define rank rank1231231

const int MAX_N = 1e3;

int parent[MAX_N];
int rank[MAX_N];

bool used[MAX_N];
int op[MAX_N];

void Init(int n) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        used[i] = false;
        op[i] = -1;
    }
}

int GetParent(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = GetParent(parent[v]);
}

bool Unite(int v1, int v2) {
    v1 = GetParent(v1);
    v2 = GetParent(v2);

    if (v1 == v2) {
        return false;
    }

    if (rank[v1] < rank[v2]) {
        swap(v1, v2);
    }

    parent[v2] = v1;
    if (rank[v1] == rank[v2]) {
        ++rank[v1];
    }

    return true;
}

struct TEdge {
    int From;
    int To;
    int Cost;
    int Index;
};

bool operator < (const TEdge& lhs, const TEdge& rhs) {
    return lhs.Cost < rhs.Cost;
}

int main() {
    /*
    freopen("input2.txt", "w", stdout);
    const int N = 1000;
    const int M = N * (N - 1) / 2;
    cout << N << " " << M << " " << N << endl;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            cout << i << " " << j << " " << 0 << endl;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << 1 << " " << M << endl;
    }
    return 0;
    */
    // freopen("input2.txt", "r", stdin);

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    vector<TEdge> edges(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edges[i].From, &edges[i].To, &edges[i].Cost);
        --edges[i].From;
        --edges[i].To;
        edges[i].Index = i;
    }

    random_shuffle(edges.begin(), edges.end());
    sort(edges.begin(), edges.end());

    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;

        Init(n);

        int failId = -1;
        for (int j = m - 1; j >= 0; --j) {
            if (edges[j].Index >= l && edges[j].Index <= r) {
                int v1 = GetParent(edges[j].From);
                int v2 = GetParent(edges[j].To);

                if (!used[v1] && !used[v2]) {
                    used[v1] = used[v2] = true;
                } else if (!used[v1]) {
                    used[v1] = true;
                    Unite(v1, op[v2]);
                } else if (!used[v2]) {
                    used[v2] = true;
                    Unite(v2, op[v1]);
                } else {
                    if (v1 == op[v2]) {
                        continue;
                    }
                    if (v1 == v2) {
                        failId = j;
                        break;
                    }
                    Unite(v2, op[v1]);
                    Unite(v1, op[v2]);
                }
                v1 = GetParent(v1);
                v2 = GetParent(v2);

                op[v1] = v2;
                op[v2] = v1;
            }
        }

        if (failId == -1) {
            printf("-1\n");
        } else {
            printf("%d\n", edges[failId].Cost);
        }
    }

    return 0;
}