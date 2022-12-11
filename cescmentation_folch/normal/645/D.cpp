#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

const int N = 1e6 + 10;

vpi G[N];

bool top(int n, int k) {
    int R[n];
    memset(R, 0, sizeof R);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            if (G[i][j].second <= k) {
                R[G[i][j].first]++;
            }
        }
    }
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        if (R[i] == 0) Q.push(i); 
    }
    while (!Q.empty()) {
        if (Q.size() > 1) return false;
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < G[x].size(); ++i) {
            if (G[x][i].second <= k) {
                int y = G[x][i].first;
                --R[y];
                if (R[y] == 0) Q.push(y);
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].push_back(pi(y, i + 1));
    }
    
    int a = 0;
    int b = m + 1;
    
    while (a + 1 < b) {
        int c = (a + b)/2;
        
        if (top(n, c)) b = c;
        else a = c;
    }
    
    if (b == m + 1) cout << -1 << endl;
    else cout << b << endl;
}