#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

#include <cassert>
using namespace std;

const int MAX_N = 1e3;

using TShelfBase = bitset<MAX_N>;

struct TShelf {
    void set(int pos, bool val) {
        Base.set(pos, val);
    }

    int count(int m) {
        return Base.count() + GetFixValue(m);
    }

    void flip() {
        Flipped ^= true;
        Base.flip();
    }

    int GetFixValue(int m) {
        if (Flipped) {
            return -(MAX_N - m);
        } else {
            return 0;
        }
    }

    bool Flipped = false;
    TShelfBase Base;
};

vector<TShelf> shelves;

struct TQuery {
    int Type;
    int I;
    int J;
    int K;
};

vector<TQuery> queries;

vector<int> parent;

vector<int> initialShelfIds;

vector<int> shelfIdFrom;
vector<int> shelfIdTo;

vector<int> result;

int main() {
    /*
    freopen("input.txt", "w", stdout);
    const int LIM_N = 1e3;
    const int LIM_Q = 1e5;
    printf("%d %d %d\n", LIM_N, LIM_N, LIM_Q);
    for (int i = 0; i < LIM_Q; ++i) {
        printf("1 1 1\n");
    }
    return 0;
    freopen("input.txt", "r", stdin);
    */
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);

    parent.resize(q + 1);
    parent[0] = -1;

    queries.resize(q + 1);
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &queries[i].Type);
        TQuery& cur = queries[i];
        parent[i] = i - 1;
        if (cur.Type == 1) {
            scanf("%d%d", &cur.I, &cur.J);
            --cur.I;
            --cur.J;
        } else if (cur.Type == 2) {
            scanf("%d%d", &cur.I, &cur.J);
            --cur.I;
            --cur.J;
        } else if (cur.Type == 3) {
            scanf("%d", &cur.I);
            --cur.I;
        } else {
            scanf("%d", &cur.K);
            parent[i] = cur.K;
        }
    }

    initialShelfIds.resize(n);
    for (int i = 0; i < n; ++i) {
        shelves.push_back(TShelf());
        initialShelfIds[i] = shelves.size() - 1;
    }

    shelfIdFrom.resize(q + 1);
    shelfIdTo.resize(q + 1);

    vector<int> prevPtr(q + 1);
    vector<int> curPtr(q + 1);
    for (int curId = 0; curId < n; ++curId) {
        prevPtr[0] = curPtr[0] = initialShelfIds[curId];

        for (int i = 1; i <= q; ++i) {
            const TQuery& query = queries[i];

            prevPtr[i] = curPtr[i] = curPtr[parent[i]];

            if (query.Type == 1 || query.Type == 2 || query.Type == 3) {
                if (query.I == curId) {
                    shelves.push_back(TShelf());

                    curPtr[i] = shelves.size() - 1;

                    shelfIdFrom[i] = prevPtr[i];
                    shelfIdTo[i] = curPtr[i];
                }
            }
        }
    }

    result.resize(q + 1);
    result[0] = 0;

    for (int i = 1; i <= q; ++i) {
        const TQuery& query = queries[i];

        if (query.Type == 4) {
            result[i] = result[parent[i]];
        } else {
            result[i] = result[parent[i]];

            const int fromId = shelfIdFrom[i];
            const int toId = shelfIdTo[i];

            result[i] -= shelves[fromId].count(m);

            if (query.Type == 1) {
                shelves[toId] = shelves[fromId];
                shelves[toId].set(query.J, 1);
            } else if (query.Type == 2) {
                shelves[toId] = shelves[fromId];
                shelves[toId].set(query.J, 0);
            } else {
                shelves[toId] = shelves[fromId];
                shelves[toId].flip();
            }

            result[i] += shelves[toId].count(m);
        }
    }

    for (int i = 1; i <= q; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}