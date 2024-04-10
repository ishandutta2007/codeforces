#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int B[111][111][111];
int C[111], D[111][111], E[111];

void tc() {
    vector<int> V;
    string s;
    int n, i, j, k, u, v, w, t;
    
    cin >> n;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) for (k = 1; k <= n; k++) {
        B[i][j][k] = 0;
        D[i][j] = 0;
    }
    fill(C, C + n + 1, 0);
    fill(E, E + n + 1, 0);
    
    for (i = 1; i < n; i++) {
        for (j = 1; j <= n - i; j++) {
            cin >> s;
            for (k = 1; k <= n; k++) {
                B[i][i + j][k] = B[i + j][i][k] = s[k - 1] - '0';
                if (s[k - 1] == '1') C[k] += 2;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        t = min_element(C + 1, C + n + 1) - C;
        C[t] = 1e9; E[t] = 1;
        V.push_back(t);
        
        for (j = 1; j <= n; j++) if (!E[j]) {
            for (k = 1; k <= n; k++) {
                if (B[j][t][k]) C[k]--;
                if (B[t][j][k]) C[k]--;
            }
        }
    }
    reverse(V.begin(), V.end());
   
    D[V[0]][V[1]] = D[V[1]][V[0]] = 1;
    
    for (i = 2; i < n; i++) {
        u = V[i]; v = -1;
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                if (D[j][k] == 1 && B[j][u][k]) {
                    v = k;
                }
            }
        }
        
        if (v == -1) {
            cout << "No\n";
            return;
        }
        
        for (j = 0; j < i; j++) {
            w = V[j];
            D[u][w] = D[w][u] = D[v][w] + 1;
        }
    }
    
    sort(V.begin(), V.end());
    for (i = 0; i < n; i++) {
        if (V[i] != i + 1) {
            cout << "No\n";
            return;
        }
    }
    
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) for (k = 1; k <= n; k++) {
        if (i == j) continue;
        if ((D[i][k] == D[j][k]) != B[i][j][k]) {
            cout << "No\n";
            return;
        }
    }
    
    cout << "Yes\n";
    for (i = 1; i <= n; i++) for (j = i + 1; j <= n; j++) {
        if (D[i][j] == 1) cout << i << " " << j << "\n";
    }
    
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    
    cin >> t;
    
    for (; t--; ) {
        tc();
    }
    
    return 0;
}