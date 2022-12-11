#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;
typedef vector<int> VI;
typedef vector<VI> VVI;

vector <VVI> ans;

void pinta(int x, int y, int z) {
    if (x < 0 || y < 0) return;
    ans[x][y][z] = -1;
    
}

void tunel(int a, int b) {
    if (a == b) return;
    int x = 20+3*a, y = 20+3*b;
    for (int i = a; i <= b-2; ++i) {
        if (i%2 == 0) {
            
            for (int i1 = -1; i1 <= 1; ++i1) {
                for (int i2 = -1; i2 <= 1; ++i2) {
                    if (i1 != 0 || i2 != 0) pinta(x+i1, y+i2, i);
                }
            }
            
        }
        else {
            ans[x][y][i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <vector<int> >d(n, vector <int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> d[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = (d[i][j] | (d[i][k]&d[k][j]));
            }
        }
    }
    int ccnum = 0;
    vector <int>cc(n, -1);
    for (int i = 0; i < n; ++i) {
        if (cc[i] == -1) {
            cc[i] = ccnum;
            for (int j = i+1; j < n; ++j) {
                if (d[i][j] && d[j][i]) cc[j] = ccnum;
            }
            ccnum++;
        }
    }
    vector <vector<int> >g(ccnum, vector <int>(ccnum, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j]) {
                g[cc[i]][cc[j]] = 1;
            }
        }
    }
    vector <int>deg(ccnum, 0);
    for (int i = 0; i < ccnum; ++i) {
        for (int j = 0; j < ccnum; ++j) {
            if (g[i][j] == 1 && i != j) {
                deg[j]++;
            }
        }
    }
    queue<int>q;
    for (int i = 0; i < ccnum; ++i) {
        if (deg[i] == 0) q.push(i);
    }
    vector <int>ord(ccnum);
    int ordd = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ord[u] = ordd++;
        for (int i = 0; i < ccnum; ++i) {
            if (g[u][i] == 1) {
                deg[i]--;
                if (deg[i] == 0) q.push(i);
            }
        }
    }
    int N = 100;
    ans = vector <VVI> (N, VVI(N, vector <int>(20, 0)));
    for (int z = 1; z < 20; z += 2) {
        for (int x = 0; x < N; ++x) {
            for (int y = 0; y < N; ++y) {
                ans[x][y][z] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans[i][i][2*ord[cc[i]]] = i+1;
    }
    for (int i = 0; i < ccnum; ++i) {
        for (int j = 0; j < ccnum; ++j) {
            if (g[i][j]) {
                tunel(2*ord[i]+1, 2*ord[j]+1);
            }
        }
    }
    cout << N << " " << N << " " << 20 << endl;
    for (int z = 0; z < 20; ++z) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (ans[i][j][z] == 0) cout << '.';
                else if (ans[i][j][z] == -1) cout << '#';
                else cout << ans[i][j][z];
            }
            cout << endl;
        }
        cout << endl;
    }
}