#include <bits/stdc++.h>

using namespace std;


int G[1000][1000];
int D[1000];
int Letter[1000];
int n;
vector<int> Graf[1000];

void dfs(int node, int color) {
    Letter[node] = color;

    for(auto vec : Graf[node]) {
        if(!Letter[vec])
            dfs(vec, 4-color);
    }
}

void Output() {
    cout << "Yes\n";
    for(int i=1; i<=n; i++) {
        cout << char(Letter[i] + 'a' - 1) ;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug", "r", stdin);
    #endif // ONLINE_JUDGE


    int m, a, b;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        G[i][i] = 1;


    while(m--) {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
        D[a]++;
        D[b]++;
    }

    for(int i=1; i<=n; i++) {
        if(D[i] == n-1) {
            Letter[i] = 2;
        } else {
            for(int j=1; j<=n; j++) {
                if(!G[i][j]) {
                    Graf[i].push_back(j);
                    Graf[j].push_back(i);
                }
            }
        }
    }

    Letter[n+1] = 2;

    int root = 1;
    while(Letter[root]) root++;

    if(root == n+1) {
        Output();
    } else {
        dfs(root, 1);
        for(int i=1; i<=n; i++) {
            if(!Letter[i]) {
                cout << "No";
                return 0;
            }
        }

        for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
                if(abs(Letter[i] - Letter[j]) <= 1 && G[i][j] == 0) {
                    cout << "No";
                    return 0;
                }
                if(abs(Letter[i] - Letter[j]) > 1 && G[i][j] == 1) {
                    cout << "No";
                    return 0;
                }
            }



        Output();
    }
    return 0;
}