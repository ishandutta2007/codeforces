#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <functional>

#include <cassert>
#include <cstdio>
using namespace std;

const int MAX_A = 1e6;
const int MIN_A = 0;

int xorSums[MAX_A + 1];

void BuildXorSums() {
    xorSums[0] = 0;
    for (int i = 1; i <= MAX_A; ++i) {
        xorSums[i] = (i ^ xorSums[i - 1]);
    }
}

const int C = 500;

struct TQuery {
    int L;
    int R;
    int I;
};

inline int GetBit(int mask, int num) {
    return (mask >> num) & 1;
}

const int BIT_COUNT = 20;

struct TNode {
    int Next[2];
    int Marker;
};

const int MAX_N = 5e4;
const int MAX_NODE_COUNT = 2 * (MAX_N * 20 + 100);

TNode nodes[MAX_NODE_COUNT];
int nodeCount;

void InitMemory() {
    nodeCount = 0;
}

void Clear(int index) {
    nodes[index].Next[0] = nodes[index].Next[1] = -1;
}

int GetNewNode() {
    Clear(nodeCount);
    return nodeCount++;
}

int GetNewMinNode() {
    int newNode = GetNewNode();
    nodes[newNode].Marker = MAX_A + 1;
    return newNode;
}

int GetNewMaxNode() {
    int newNode = GetNewNode();
    nodes[newNode].Marker = -1;
    return newNode;
}

void AddMin(int v, int marker, int val) {
    nodes[v].Marker = min(nodes[v].Marker, marker);
    for (int i = BIT_COUNT - 1; i >= 0; --i) {
        int b = GetBit(val, i);
        if (nodes[v].Next[b] == -1) {
            nodes[v].Next[b] = GetNewMinNode();
        }
        v = nodes[v].Next[b];
        nodes[v].Marker = min(nodes[v].Marker, marker);
    }
}

void AddMax(int v, int marker, int val) {
    nodes[v].Marker = max(nodes[v].Marker, marker);
    for (int i = BIT_COUNT - 1; i >= 0; --i) {
        int b = GetBit(val, i);
        if (nodes[v].Next[b] == -1) {
            nodes[v].Next[b] = GetNewMaxNode();
        }
        v = nodes[v].Next[b];
        nodes[v].Marker = max(nodes[v].Marker, marker);
    }
}

int GetMaxXorWithSmallerMarker(int v, int marker, int val) {
    int result = 0;
    for (int i = BIT_COUNT - 1; i >= 0; --i) {
        int b = GetBit(val, i);
        if (nodes[v].Next[1 - b] != -1 && nodes[nodes[v].Next[1 - b]].Marker <= marker) {
            v = nodes[v].Next[1 - b];
            result += (1 - b) * (1 << i);
        } else if (nodes[v].Next[b] != -1 && nodes[nodes[v].Next[b]].Marker <= marker) {
            v = nodes[v].Next[b];
            result += b * (1 << i);
        } else {
            return 0;
        }
    }
    return result ^ val;
}

int GetMaxXorWithGreaterMarker(int v, int marker, int val) {
    int result = 0;
    for (int i = BIT_COUNT - 1; i >= 0; --i) {
        int b = GetBit(val, i);
        if (nodes[v].Next[1 - b] != -1 && nodes[nodes[v].Next[1 - b]].Marker >= marker) {
            v = nodes[v].Next[1 - b];
            result += (1 - b) * (1 << i);
        } else if (nodes[v].Next[b] != -1 && nodes[nodes[v].Next[b]].Marker >= marker) {
            v = nodes[v].Next[b];
            result += b * (1 << i);
        } else {
            return 0;
        }
    }
    return result ^ val;
}

int GetResultStraight(int l, int r, const vector<int>& a) {
    int wasNodeCount = nodeCount;

    int maxRoot = GetNewMaxNode();
    int minRoot = GetNewMinNode();

    int result = 0;
    for (int i = l; i <= r; ++i) {
        AddMax(maxRoot, a[i], xorSums[a[i]]);
        AddMin(minRoot, a[i], xorSums[a[i] - 1]);
        result = max(result, GetMaxXorWithSmallerMarker(minRoot, a[i], xorSums[a[i]]));
        result = max(result, GetMaxXorWithGreaterMarker(maxRoot, a[i], xorSums[a[i] - 1]));
    }

    nodeCount = wasNodeCount;

    return result;
}

int main() {
    // freopen("input.txt", "r", stdin);

    BuildXorSums();

    int n, m;
    scanf("%d%d", &n, &m);

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<TQuery> q(m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].L, &q[i].R);
        --q[i].L;
        --q[i].R;
        q[i].I = i;
    }

    vector<vector<TQuery>> groups;
    for (int i = 0; i * C < n; ++i) {
        groups.push_back(vector<TQuery>());
        int il = i * C;
        int ir = min((i + 1) * C, n);
        for (int j = 0; j < m; ++j) {
            if (q[j].L >= il && q[j].L < ir) {
                groups.back().push_back(q[j]);
            }
        }
        sort(groups.back().begin(), groups.back().end(), 
            [] (const TQuery& lhs, const TQuery& rhs) {
                return lhs.R < rhs.R;
            }
        );
    }

    vector<int> results(m);
    for (int i = 0; i < (int) groups.size(); ++i) {
//        int il = i * C;
        int ir = min((i + 1) * C, n);

        {
            for (int qi = 0; qi < (int) groups[i].size(); ++qi) {
                const TQuery& q = groups[i][qi];

                if (q.R < ir) {
                    InitMemory();
                    results[q.I] = GetResultStraight(q.L, q.R, a);
                }
            }
        }

        if (ir < n) {
            InitMemory();

            int maxRoot = GetNewMaxNode();
            int minRoot = GetNewMinNode();

            int rightResult = 0;

            const auto& addToMo = [&a, maxRoot, minRoot, &rightResult] (int index) {
                AddMax(maxRoot, a[index], xorSums[a[index]]);
                AddMin(minRoot, a[index], xorSums[a[index] - 1]);
                rightResult = max(rightResult, GetMaxXorWithSmallerMarker(minRoot, a[index], xorSums[a[index]]));
                rightResult = max(rightResult, GetMaxXorWithGreaterMarker(maxRoot, a[index], xorSums[a[index] - 1]));
            };

            int r = ir;
            addToMo(r);
            for (int qi = 0; qi < (int) groups[i].size(); ++qi) {
                const TQuery& q = groups[i][qi];

                if (q.R < ir) {
                    continue;
                }

                while (r < q.R) {
                    ++r;
                    addToMo(r);
                }

                int curResult = rightResult;
                for (int j = q.L; j < ir; ++j) {
                    curResult = max(curResult, GetMaxXorWithSmallerMarker(minRoot, a[j], xorSums[a[j]]));
                    curResult = max(curResult, GetMaxXorWithGreaterMarker(maxRoot, a[j], xorSums[a[j] - 1])); 
                }
                curResult = max(curResult, GetResultStraight(q.L, ir - 1, a));

                results[q.I] = curResult;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        printf("%d\n", results[i]);
    }

    return 0;
}