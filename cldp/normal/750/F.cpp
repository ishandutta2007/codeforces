#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 8;
const int INF = 1000000007;

int K[MAXN];
int X[MAXN][10];
bool Z[MAXN];

bool BFS(int a) {
    for (int i = 0; i < 3; ++i) {
        if (Z[X[a][i]]) continue;
        a = X[a][i];
        break;
    }
    queue<int> Q;
    Q.push(a);
    int cnt = 0;
    while (!Q.empty()) {
        ++cnt;
        a = Q.front();
        Q.pop();
        if (cnt == 7) {
            cout << "! " << a << endl;
            return true;
        }
        Z[a] = true;
        cout << "? " << a << endl;
        cin >> K[a];
        for (int i = 0; i < K[a]; ++i) cin >> X[a][i];
        if (K[a] == 2) {
            cout << "! " << a << endl;
            return true;
        }
        for (int i = 0; i < K[a]; ++i) {
            if (!Z[X[a][i]]) Q.push(X[a][i]);
        }
    }
    return false;
}

bool DFS(int a, vector<int> &S) {
    Z[a] = true;
    while (a == 1 || K[a] != 1) {
        int b = -1;
        for (int i = 0; i < K[a]; ++i) {
            if (Z[X[a][i]]) continue;
            b = X[a][i];
            break;
        }
        Z[b] = true;
        cout << "? " << b << endl;
        S.push_back(b);
        cin >> K[b];
        for (int i = 0; i < K[b]; ++i) cin >> X[b][i];
        if (K[b] == 2) {
            cout << "! " << b << endl;
            return true;
        }
        a = b;
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        bool flag = false;
        memset(X, 0, sizeof(X));
        memset(K, 0, sizeof(K));
        memset(Z, 0, sizeof(Z));
        int H;
        cin >> H;
        cout << "? 1" << endl << flush;
        cin >> K[1];
        for (int i = 0; i < K[1]; ++i) cin >> X[1][i];
        if (K[1] == 2) {
            cout << "! 1" << endl << flush;
            continue;
        }

        vector<int> S;
        if (K[1] == 1) {
            S.push_back(1);
            if (DFS(1, S)) continue;
            S.resize(S.size() / 2 + 1);
        } else {
            vector<int> SS;
            S.push_back(1);
            if (DFS(1, S)) continue;
            SS.push_back(1);
            if (DFS(1, SS)) continue;
            if (S.size() < SS.size()) swap(S, SS);
            reverse(S.begin(), S.end());
            if (S.size() > SS.size()) {
                S.pop_back();
                S.resize((S.size() + SS.size()) / 2 + 1);
            }
        }

        int T = S[S.size() - 1];
        if (S.size() >= 5) {
            BFS(T);
            continue;
        }
        while (true) {
            vector<int> S1;
            if (DFS(T, S1)) break;
            reverse(S1.begin(), S1.end());
            if (S1.size() + S.size() >= 7) {
                BFS(S1[(S1.size() + S.size()) / 2]);
                break;
            }
            S1.resize((S1.size() + S.size()) / 2 + 1);
            S = S1;
            T = S[S.size() - 1];
        }
    }

    return 0;
}