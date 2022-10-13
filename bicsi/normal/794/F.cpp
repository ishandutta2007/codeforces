#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int kMaxN = 400000;

long long Count[kMaxN][10];
int Remap[kMaxN][10];

void push(int node, int b, int e) {
    static long long aux[10];
    
    if (b != e) {
        for (int son = 2 * node; son < 2 * node + 2; ++son) {
            for (int i = 0; i < 10; ++i) {
                Remap[son][i] = Remap[node][Remap[son][i]];
            }
        }
    }

    memset(aux, 0, sizeof(aux));
    for (int i = 0; i < 10; ++i) {
        aux[Remap[node][i]] += Count[node][i];
        Remap[node][i] = i;
    }
    memcpy(Count[node], aux, sizeof(aux));

}

void pull(int node, int b, int e) {
    if (b != e) {
        int m = (b + e) / 2;
        push(node * 2, b, m);
        push(node * 2 + 1, m + 1, e);
    }

    for (int i = 0; i < 10; ++i)
        Count[node][i] = Count[node * 2][i] + Count[node * 2 + 1][i];
}

void treeInit(int node, int b, int e, vector<int> &V) {
    for (int i = 0; i < 10; ++i) 
        Remap[node][i] = i;
    
    if (b == e) {
        int no = V[b], pw = 1;
        while (no) {
            int dig = no % 10; no /= 10;
            Count[node][dig] += pw; pw *= 10;
        }
    } else {
        int m = (b + e) / 2;
        treeInit(node * 2, b, m, V);
        treeInit(node * 2 + 1, m + 1, e, V);
        pull(node, b, e);
    }
}

void treeUpdate(int node, int b, int e, int l, int r, int x, int y) {
    push(node, b, e);
    if (l > r) return;

    if (b == l && e == r) {
        Remap[node][x] = y;
        push(node, b, e);
    } else {
        int m = (b + e) / 2;
        treeUpdate(node * 2, b, m, l, min(r, m), x, y);
        treeUpdate(node * 2 + 1, m + 1, e, max(l, m + 1), r, x, y);
        pull(node, b, e);
    }
}

long long treeQuery(int node, int b, int e, int l, int r) {
    push(node, b, e);
    if (l > r) return 0;

    if (b == l && e == r) {
        long long ans = 0;
        for (int i = 0; i < 10; ++i) {
            ans += Count[node][i] * i;
        }
        return ans;
    }
    
    int m = (b + e) / 2;
    return treeQuery(node * 2, b, m, l, min(r, m)) +
        treeQuery(node * 2 + 1, m + 1, e, max(m + 1, l), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> V(n);
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    treeInit(1, 0, n - 1, V);

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r; 
        --l; --r;
        
        if (type == 1) {
            int x, y; cin >> x >> y;
            treeUpdate(1, 0, n - 1, l, r, x, y);
        } else {
            cout << treeQuery(1, 0, n - 1, l, r) << '\n';
        }
    }
    return 0;
}