#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> G[1000];
bool visited[1000];

void dfs(int n) {
    visited[n] = true;
    for(int x : G[n]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}

int main() {
    bool flag = false;
    cin >> N >> M;
    for(int n = 0; n < N; ++n) {
        int a;
        cin >> a;
        while(a--) {
            flag = true;
            int x;
            cin >> x;
            G[n].push_back(x + 200);
            G[x + 200].push_back(n);
        }
    }
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        if(!visited[n]) {
            ++ans;
            dfs(n);
        }
    }
    cout << (ans - flag) << '\n';
}