#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#include <cstring>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

using TMatr = vector<vector<long long>>;

TMatr operator * (const TMatr& lhs, const TMatr& rhs) {
    TMatr result(lhs.size(), vector<long long>(rhs[0].size(), -1));
    for (int i = 0; i < (int) result.size(); ++i) {
        for (int j = 0; j < (int) result[i].size(); ++j) {
            for (int t = 0; t < (int) lhs[i].size(); ++t) {
                if (lhs[i][t] < 0 || rhs[t][j] < 0) {
                    continue;
                }
                result[i][j] = max(result[i][j], lhs[i][t] + rhs[t][j]);
            }
        }
    }
    return result;
}

TMatr GetBinaryPow(TMatr a, long long pw) {
    TMatr result(a.size(), vector<long long>(a.size(), -1));
    for (int i = 0; i < (int) a.size(); ++i) {
        result[i][i] = 0;
    }
    while (pw > 0) {
        if (pw & 1) {
            result = result * a;
        }
        a = a * a;
        pw >>= 1;
    }
    return result;
}

const int MAX_C = 26;

struct TNode {
    int Next[MAX_C];
    int SuffLink;
    long long Sum;
    long long SuffLinkSum;
};

const int MAX_NODE_COUNT = 1e3;

TNode nodes[MAX_NODE_COUNT];
int nodeCount;

void ClearNode(int node) {
    nodes[node].Sum = 0;
    nodes[node].SuffLink = -1;
    for (int i = 0; i < MAX_C; ++i) {
        nodes[node].Next[i] = -1;
    }
    nodes[node].SuffLinkSum = 0;
}

void Init() {
    ClearNode(0);
    nodeCount = 1;
}

int GetNewNode() {
    ClearNode(nodeCount);
    ++nodeCount;
    return nodeCount - 1;
}

void AddString(const char* s, int len, long long sum) {
    int v = 0;
    for (int i = 0; i < len; ++i) {
        int c = s[i] - 'a';

        if (nodes[v].Next[c] == -1) {
            nodes[v].Next[c] = GetNewNode();
        }

        v = nodes[v].Next[c];
    }
    nodes[v].Sum += sum;
}

const int MAX_SLEN = 222;

char buffer[MAX_SLEN];

int main() {
    int n;
    long long l;
    scanf("%d" LLD_SPEC, &n, &l);

    vector<long long> sums(n);
    for (int i = 0; i < n; ++i) {
        scanf(LLD_SPEC, &sums[i]);
    }

    Init();

    for (int i = 0; i < n; ++i) {
        scanf("%s", buffer);

        AddString(buffer, strlen(buffer), sums[i]);
    }

    {
        vector<bool> used(nodeCount, false);
        used[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v != 0) {
                nodes[v].SuffLinkSum = nodes[v].Sum + nodes[nodes[v].SuffLink].SuffLinkSum;
            }

            for (int i = 0; i < MAX_C; ++i) {
                int u = nodes[v].Next[i];

                if (u != -1 && !used[u]) {
                    used[u] = true;
                    q.push(u);

                    if (v == 0) {
                        nodes[u].SuffLink = 0;
                    } else {
                        int x = nodes[v].SuffLink;
                        while (x > 0 && nodes[x].Next[i] == -1) {
                            x = nodes[x].SuffLink;
                        }
                        if (nodes[x].Next[i] != -1) {
                            x = nodes[x].Next[i];
                        }
                        nodes[u].SuffLink = x;
                    }
                }
            }
        }
    }

    TMatr tr(nodeCount, vector<long long>(nodeCount, -1));

    for (int v = 0; v < nodeCount; ++v) {
        tr[v][v] = 0;

        auto doItr = [&tr] (int iv, int v) {
            for (int c = 0; c < MAX_C; ++c) {
                if (nodes[v].Next[c] != -1) {
                    int u = nodes[v].Next[c];

                    tr[iv][u] = max(tr[iv][u], nodes[u].SuffLinkSum);
                }
            }
        };

        doItr(v, v);

        int x = v;
        while (x > 0) {
            x = nodes[x].SuffLink;

            doItr(v, x);
        }
    }

    /*
    for (int i = 0; i < nodeCount; ++i) {
        for (int j = 0; j < nodeCount; ++j) {
            printf(LLD_SPEC " ", tr[i][j]);
        }
        printf("\n");
    }
    */

    tr = GetBinaryPow(tr, l);

    long long result = 0;
    for (int j = 0; j < nodeCount; ++j) {
        result = max(result, tr[0][j]);
    }

    printf(LLD_SPEC "\n", result);

    return 0;
}