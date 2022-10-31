#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int n = 20;
int T;
string s, t;
bool G[n][n], seen[n], is_DAG[1<<n];
int D[n];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while(T--) {
        int tmp; cin >> tmp;
        cin >> s >> t;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) G[i][j] = false;
            D[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            int u = s[i]-'a', v = t[i]-'a';
            if(u == v) continue;
            G[u][v] = G[v][u] = true;
            D[u] |= 1<<v;
        }
        int comp = 0;
        for (int i = 0; i < n; i++) seen[i] = false;
        for (int i = 0; i < n; i++) {
            if(seen[i]) continue;
            comp++;
            seen[i] = true;
            queue<int> q; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 0; v < n; v++) {
                    if(G[u][v] && !seen[v]) {
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
        }
        int largest_DAG = 0;
        is_DAG[0] = true;
        for (int b = 1; b < (1<<n); b++) {
            is_DAG[b] = false;
            int z = 0;
            for (int k = 0; k < n; k++) {
                if((b & (1<<k)) == 0) continue;
                z++;
                if((b & D[k]) == 0 && is_DAG[b^(1<<k)])
                    is_DAG[b] = true;
            }
            if(is_DAG[b] && largest_DAG < z) largest_DAG = z;
        }
        cout << 2*n-comp-largest_DAG << "\n";
    }
    return 0;
}