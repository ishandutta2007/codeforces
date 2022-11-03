#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int N, M, P, Q;
char A[260][260];
unsigned B[260][260];
ii visited[260][260];

void bfs(int n, int m) {
    vector<ii> Q1, Q2;
    int k = Q * (A[n][m] - 'A' + 1);
    Q1.emplace_back(n, m);
    visited[n][m] = ii(n, m);
    while(k > 0) {
        for(auto& i : Q1) {
            B[i.first][i.second] += k;
            //cerr << i.first << ' ' << i.second << ' ' << k << endl;
            for(int j = 0; j < 4; ++j) {
               int x = i.first + dx[j], y = i.second + dy[j];
               if(x >= 0 && x < N && y >= 0 && y < M && A[x][y] != '*' && visited[x][y] != ii(n, m)) {
                   visited[x][y] = ii(n, m);
                   Q2.emplace_back(x, y);
               }
            }
        }
        swap(Q1, Q2);
        Q2.clear();
        k /= 2;
    }
}

int main() {
    cin >> N >> M >> Q >> P;
    for(int n = 0; n < N; ++n) {
        cin >> A[n];
    }
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            visited[n][m] = ii(-1, -1);
        }
    }
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            if('A' <= A[n][m] && A[n][m] <= 'Z') {
                bfs(n, m);
            }
        }
    }
    /*for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            cout << B[n][m] << ' ';
        }
        cout << '\n';
    }*/
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            if(B[n][m] > P) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}