#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

struct cosa {
    int first, second, ind;
};

bool comp(cosa a, cosa b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

const int N = 3010;

int D[N][N];
int K[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, p, s;
    cin >> n >> p >> s;
    vector<cosa> V(n);
    for (int i = 0; i < n; ++i) cin >> V[i].first;
    for (int i = 0; i < n; ++i) cin >> V[i].second;
    for (int i = 0; i < n; ++i) V[i].ind = i + 1;
    sort(V.begin(), V.end(), comp);
    memset(D, -1, sizeof D);
    D[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (D[i][j] == -1) continue;
            if (D[i + 1][j] == -1 or D[i + 1][j] < D[i][j] + V[i].first) {
                D[i + 1][j] = D[i][j] + V[i].first;
                K[i + 1][j] = 0;
            }
            if (D[i + 1][j + 1] == -1 or D[i + 1][j + 1] < D[i][j] + V[i].second) {
                D[i + 1][j + 1] = D[i][j] + V[i].second;
                K[i + 1][j + 1] = -1;
            }
        }
    }
    pi T;
    int res = -1;
    priority_queue<pi> Q;
    vi Ka;
    int sum = 0;
    for (int i = n - 1; i >= p + s; --i) Q.push(pi(V[i].second, V[i].ind));
    for (int i = p + s; i >= p; --i) {
        int r = i - p;
        if (res < D[i][r] + sum) {
            res = D[i][r] + sum;
            T = pi(i, r);
        }
        Q.push(pi(V[i - 1].second, V[i - 1].ind));
        sum += Q.top().first;
        Ka.push_back(Q.top().second);
        Q.pop();
    }
    vi A;
    vi B;
    for (int i = 0; i < s - T.second; ++i) B.push_back(Ka[i]);
    int i = T.first;
    int k = T.second;
    while (i) {
        if (K[i][k] == -1) B.push_back(V[i - 1].ind);
        else A.push_back(V[i - 1].ind);
        k += K[i][k];
        --i;
    }
    cout << res << '\n';
    for (int i = 0; i < (int)A.size(); ++i) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    for (int i = 0; i < (int)B.size(); ++i) {
        if (i) cout << ' ';
        cout << B[i];
    }
    cout << '\n';
}