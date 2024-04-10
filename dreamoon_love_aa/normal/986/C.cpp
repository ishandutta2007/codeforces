#include <algorithm>
#include <iostream>
#include <numeric>
#include <bitset>
#include <vector>
using namespace std;

#define N 22
#define M (1 << N)
using ll = long long;

bitset<M * 2> visited;

int n, m;
int appeared_in_a[M * 2];
int a[M];

void dfs0(int id);

void dfs(int now) {
    if(visited[now]) return;
    visited[now] = 1;
    if(appeared_in_a[now]) {
        dfs0(appeared_in_a[now]);
    }
    for (int i = 0; i < n; i++) {
        if (now & (1 << i)) {
            dfs(now ^ (1 << i));
        }
    }
}

void dfs0(int id) {
    if(visited[id + M]) return;
    visited[id + M] = 1;
    dfs(a[id] ^ ((1 << n) - 1));
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        appeared_in_a[a[i]] = i;
    }
    int an = 0;
    for (int i = 1; i <= m; i++) {
        if (!visited[M + i]) {
            an++;
            dfs0(i);
        }
    }
    cout << an << '\n';
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    solve();
    return 0;
}