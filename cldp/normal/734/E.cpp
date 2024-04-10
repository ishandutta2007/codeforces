#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000007;
const int MAXN = 200010;

int N;
int C[MAXN], D[MAXN];
vector<int> X[MAXN];

int dfs(int a) {
    C[a] = 1;
    for (int i = 0; i < X[a].size(); ++i) 
     if (C[X[a][i]] == 0) dfs(X[a][i]);
    return 0;
}

void findD(int a, int b) {
    D[a] = b;
    for (int i = 0; i < X[a].size(); ++i) {
        if (D[X[a][i]] != INF) continue;
        if (C[a] == C[X[a][i]]) findD(X[a][i], b); else findD(X[a][i], b + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> C[i];
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        X[x].push_back(y);
        X[y].push_back(x);
    }
    bool flag = true;
    for (int i = 1; i <= N; ++i) flag &= C[i] == C[0];
    
    if (flag) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 1; i <= N; ++i) D[i] = INF;
    findD(1, 0);
    
    int a = -1, b = 0;
    for (int i = 1; i <= N; ++i) {
        if (D[i] < b) continue;
        a = i;
        b = D[i];
    }
    
    for (int i = 1; i <= N; ++i) D[i] = INF;
    findD(a, 0);
    a = -1, b = 0;
    for (int i = 1; i <= N; ++i) {
        if (D[i] < b) continue;
        a = i;
        b = D[i];
    }
    for (int i = 1; i <= N; ++i) D[i] = INF;
    findD(a, 0);
    a = -1, b = 0;
    for (int i = 1; i <= N; ++i) {
        if (D[i] < b) continue;
        a = i;
        b = D[i];
    }
    
    cout << (b + 1) / 2 << endl;
    
    return 0;
}