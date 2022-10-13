#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000
vector<int> G[MAXN];
int D[MAXN], Parent[MAXN], State[MAXN], DU[MAXN], DD1[MAXN], DD2[MAXN], Ch[MAXN];

queue<int> Q;

void dfs1(int node) {
    for(auto vec : G[node]) {
        if(vec != Parent[node] && State[vec] != -1) {
            Parent[vec] = node;
            dfs1(vec);

            int use = DD1[vec] + 1;
            if(DD1[node] < use) {
                DD2[node] = DD1[node];
                DD1[node] = use;
                Ch[node] = vec;
            } else {
                if(DD2[node] < use)
                    DD2[node] = use;
            }
        }
    }
}

void dfs2(int node) {
    for(auto vec : G[node]) {
        if(vec != Parent[node] && State[vec] != -1) {

            if(Ch[node] == vec) {
                DU[vec] = max(DU[node], DD2[node]) + 1;
            } else {
                DU[vec] = max(DU[node], DD1[node]) + 1;
            }

            dfs2(vec);
        }
    }
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, m, a, b;
    cin>>n>>m;

    for(int i=1; i<n; i++) {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        D[a]++; D[b]++;
    }

    for(int i=1; i<=m; i++) {
        cin>>a;
        State[a] = 1;
    }

    for(int i=1; i<=n; i++) {
        if(D[i] == 1 && State[i] == 0) {
            Q.push(i);
            State[i] = -1;
        }
    }

    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for(auto vec : G[node]) {
            D[vec]--;
            if(D[vec] == 1 && State[vec] == 0) {
                Q.push(vec);
                State[vec] = -1;
            }
        }
    }

    int root = 1;
    while(State[root] != 1) root++;

    dfs1(root);
    dfs2(root);

    int sol = -1, diam = -1, nodes = 0;
    for(int i=1; i<=n; i++) {
        int dd = max(DU[i], DD1[i]);
        if(State[i] != -1 && diam < dd) {
            diam = dd;
            sol = i;
        }

        if(State[i] != -1) nodes++;
    }

    cout<<sol<<"\n"<<2*(nodes-1)-diam;

    return 0;
}