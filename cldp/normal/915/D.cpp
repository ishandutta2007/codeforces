#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 510;
const int INF = 1000000007;
const double PI = acos(-1.0);

vector<int> x[MAXN];
int IN[MAXN], II[MAXN];
bool z[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        ++IN[b];
    }

    queue<int> Q;
    for (int i = 1; i <= N; ++i) {
        if (IN[i] > 0) continue;
        Q.push(i);
    }
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        z[a] = true;
        for (int i = 0; i < x[a].size(); ++i) {
            --IN[x[a][i]];
            if (IN[x[a][i]] == 0) Q.push(x[a][i]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        cnt += z[i];
    }
    if (cnt == N) {
        cout << "YES" << endl;
        return 0;
    }

    vector<int> X;
    for (int i = 1; i <= N; ++i) {
        if (IN[i] == 1) X.push_back(i);
        II[i] = IN[i];
    }

    for (int i = 0; i < X.size(); ++i) {
        for (int j = 1; j <= N; ++j) IN[j] = II[j];
        Q.push(X[i]);
        IN[X[i]] = 0;
        int temp = 0;
        while (!Q.empty()) {
            int a = Q.front();
            Q.pop();
            ++temp;
            z[a] = true;
            for (int k = 0; k < x[a].size(); ++k) {
                --IN[x[a][k]];
                if (IN[x[a][k]] == 0) Q.push(x[a][k]);
            }
        }
        if (temp + cnt == N) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}