#include <bits/stdc++.h>

using namespace std;

int open[100100], close[100100];
vector<int> G[100100];
int C[100100], col[100100];

void dfs(int n, int p) {
    static int t = 0;
    col[t] = C[n];
    open[n] = t++;
    for(int x : G[n]) {
        if(x != p) {
            dfs(x, n);
        }
    }
    close[n] = t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    int sqrtN = sqrt(N);
    for(int n = 0; n < N; ++n) {
        cin >> C[n];
    }
    for(int n = 1; n < N; ++n) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, -1);
    vector<int> L(M), R(M), K(M);
    for(int m = 0; m < M; ++m) {
        int v;
        cin >> v >> K[m];
        --v;
        L[m] = open[v];
        R[m] = close[v];
    }
    vector<int> idx(M);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return L[i] / sqrtN < L[j] / sqrtN or (L[i] / sqrtN == L[j] / sqrtN and R[i] < R[j]);});
    vector<int> cnt_col(1e5 + 1), cnt_cnt(1e5 + 1);
    auto add = [&](int c) {
        ++cnt_col[c];
        ++cnt_cnt[cnt_col[c]];
    };
    auto rem = [&](int c) {
        --cnt_cnt[cnt_col[c]];
        --cnt_col[c];
    };
    int l = 0, r = 0;
    vector<int> ans(M);
    for(int i : idx) {
        while(L[i] < l) {
            add(col[--l]);
        }
        while(R[i] > r) {
            add(col[r++]);
        }
        while(L[i] > l) {
            rem(col[l++]);
        }
        while(R[i] < r) {
            rem(col[--r]);
        }
        ans[i] = cnt_cnt[K[i]];
    }
    for(int a : ans) {
        cout << a << '\n';
    }
}