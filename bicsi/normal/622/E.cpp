#include <iostream>
#include <queue>

using namespace std;
#define MAXN 500005

vector<int> G[MAXN], Roots, Nodes;
int Parent[MAXN], D[MAXN], P[2*MAXN];
int n;

int Find(int a) {
    if(P[a] == 0) return a;
    return P[a] = Find(P[a]);
}

void Erase(int a) {
    Nodes.push_back(Find(a));
    P[Find(a)] = Find(Find(a) + 1);
}

void dfs(int node, int root) {
    if(G[node].size() == 1 && root != node) {
        Erase(D[node]);
    }

    for(auto vec : G[node]) {
        if(vec != Parent[node]) {
            Parent[vec] = node;
            D[vec] = D[node] + 1;
            dfs(vec, root);
        }
    }
}

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(a = 0; isdigit(c); c = getchar())
        a = (a << 1) + (a << 3) + c - '0';
}

int main() {

    int a, b;
    Read(n);

    for(int i=2; i<=n; i++) {
        Read(a); Read(b);

        if(a == 1 || b == 1) {
            Roots.push_back(a ^ b ^ 1);
        } else {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }

    int sol = 0;

    for(auto root : Roots) {
        dfs(root, root);

        for(auto x : Nodes) {
            sol = max(sol, x);
            P[x] = 0;
        }
        Nodes.clear();
    }

    cout << sol + 1;
    return 0;
}