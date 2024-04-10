#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5010;
const int INF = 1000000007;
const double PI = acos(-1.0);

int K, N;
string P[MAXN];
vector<int> X[MAXN];
bool z[MAXN];
bool cz[26];

bool check(int a, int b) {
    for (int i = 1; i < K; ++i) {
        int cnt = 0;
        if (P[0][a] != P[i][a]) ++cnt;
        if (P[0][b] != P[i][b]) ++cnt;
        for (int j = 0; j < X[i].size(); ++j) {
            int &c = X[i][j];
            if (c == a || c == b) continue;
            if (P[0][c] != P[i][c]) ++cnt;
        }
        if (cnt == 2) continue;
        if (cnt == 0) {
            if (!z[i]) return false;
            continue;
        }
        return false;
    } 
    return true;
}

bool checksame(int N, int K) {
    int cnt[26], ct[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; ++i) ++cnt[P[0][i] - 'a'];
    for (int i = 1; i < K; ++i) {
        memset(ct, 0, sizeof(ct));
        for (int j = 0; j < N; ++j) ++ct[P[i][j] - 'a'];
        for (int j = 0; j < 26; ++j) {
            if (ct[j] != cnt[j]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> P[i];
        memset(cz, 0, sizeof(cz));
        for (int j = 0; j < P[i].size(); ++j) {
            if (cz[P[i][j] - 'a']) {
                z[i] = true;
                break;
            }
            cz[P[i][j] - 'a'] = true;
        }
    }
    if (!checksame(N, K)) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            if (P[0][j] != P[i][j]) X[i].push_back(j);
        }
        if (X[i].size() > 4) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            swap(P[0][i], P[0][j]);
            if (check(i, j)) {
                cout << P[0] << endl;
                return 0;
            }
            swap(P[0][i], P[0][j]);
        }
    }
    cout << -1 << endl;
    return 0;
}