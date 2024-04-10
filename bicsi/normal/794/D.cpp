#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 500000;

vector<int> G[kMaxN];
int Order[kMaxN], Link[kMaxN];
int Ans[kMaxN];
bool exists_answer = true;

void DFS(int node, int col, int maxn) {
    // cerr << "node: " << node << endl;
    Ans[node] = col;
    // cerr << "Ans[node]: " << col << endl;

    int total_vecs = 0;

    vector<int> vecs;
    for (auto vec : G[node]) {
        if (Link[vec] != vec || vec == node) continue;

        if (Ans[vec] && abs(Ans[vec] - Ans[node]) > 1) {
            // cerr << "BAD!" << node << " " << vec << endl;
            exists_answer = false;
        }
        
        if (Ans[vec] == 0) {
            vecs.push_back(vec);    
        }
    }

    if (maxn == 0 && vecs.size() > 2) exists_answer = false;
    if (maxn != 0 && vecs.size() > 1) exists_answer = false;

    if (maxn != 0) {
        for (auto vec : vecs) 
            DFS(vec, col + maxn, maxn);
    } else {
        maxn = 1;
        for (auto vec : vecs) {
            DFS(vec, col + maxn, maxn);
            maxn = -maxn;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        G[i].push_back(i);
        sort(G[i].begin(), G[i].end());
        Order[i] = i;
    }

    sort(Order + 1, Order + n + 1, [&](int a, int b) {
        return G[a] < G[b];
    });

    int last = -1;
    for (int i = 1; i <= n; ++i) {
        int now = Order[i];

        Link[now] = now;
        if (last != -1 && G[last] == G[now]) {
            Link[now] = Link[last];
            // cerr << "Merged: " << now << " " << last << endl;
        }

        last = now;
    }

    int now = 500000;
    for (int i = 1; i <= n; ++i) {
        if (Link[i] == i && Ans[i] == 0) {
            DFS(i, now, 0);
            now += 500000;
        }
    }

    if (!exists_answer) 
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) {
            cout << Ans[Link[i]] << " ";
        }
        cout << endl;
    }



	
	return 0;
}