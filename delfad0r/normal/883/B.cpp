#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int N, M, K;
int R[200200];
vector<int> G[200200];
bool visited[200200];
int minR[200200];
int in_deg[200200];
bool ok = true;

int dfs(int n) {
    if(visited[n]) {
        return minR[n];
    }
    visited[n] = true;
    for(int x : G[n]) {
        minR[n] = max(minR[n], dfs(x));
        if(!ok) {
            return -1;
        }
    }
    ++minR[n];
    if(R[n] != 0 && minR[n] > R[n]) {
        ok = false;
        return -1;
    }
    return minR[n] = max(minR[n], R[n]);
}

int main() {
    cin >> N >> M >> K;
    for(int n = 0; n < N; ++n) {
        cin >> R[n];
    }
    while(M--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        ++in_deg[b];
    }
    memset(visited, 0, sizeof(visited));
    vector<priority_queue<ii>> Q(2);
    for(int n = 0; n < N && ok; ++n) {
        if(!visited[n]) {
            dfs(n);
        }
    }
    if(!ok) {
        cout << -1 << '\n';
        return 0;
    }
    for(int n = 0; n < N; ++n) {
        if(in_deg[n] == 0) {
            Q[R[n] == 0].emplace(minR[n], n);
        }
    }
    auto remove = [&](priority_queue<ii>& q) {
        int n = q.top().second;
        q.pop();
        for(int x : G[n]) {
            if(--in_deg[x] == 0) {
                Q[R[x] == 0].emplace(minR[x], x);
            }
        }
    };
    while(K > 0) {
        int cnt = 0;
        for(auto& q : Q) {
            while(q.size() && q.top().first >= K) {
                int n = q.top().second;
                if(minR[n] > K) {
                    cout << -1 << '\n';
                    return 0;
                }
                R[n] = K;
                ++cnt;
                remove(q);
            }
        }
        if(cnt == 0) {
            if(Q[1].empty()) {
                cout << -1 << '\n';
                return 0;
            }
            int n = Q[1].top().second;
            R[n] = K;
            remove(Q[1]);
        }
        --K;
    }
    if(count(R, R + N, 0)) {
        cout << -1 << '\n';
        return 0;
    }
    for(int n = 0; n < N; ++n) {
        cout << R[n] << ' ';
    }
    cout << '\n';
}