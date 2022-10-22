#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
const int INF = 1000000007;
const double PI = acos(-1.0);

string x[MAXN];
bool cz[MAXN];
bool cc[26];

int main() {
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        memset(cc, 0, sizeof(cc));
        for (int j = 0; j < x[i].size(); ++j) {
            if (cc[x[i][j] - 'a']) {
                cout << "NO" << endl;
                return 0;
            }
            cc[x[i][j] - 'a'] = true;
        }
        cz[i] = true;
    }

    for (int t = 0; t < 26; ++t) {
        vector<pair<int, int> > X;
        for (int i = 0; i < N; ++i) {
            if (!cz[i]) continue;
            if (x[i].find(t + 'a') != string::npos) X.push_back(make_pair(i, x[i].find(t + 'a')));
        }
        if (X.size() < 2) continue;

        string P = "";
        for (int j = -26; j <= 26; ++j) {
            char cc = 0;
            for (int i = 0; i < X.size(); ++i) {
                int p = X[i].second + j;
                if (p < 0 || p >= x[X[i].first].size()) continue;
                if (cc == 0) {
                    cc = x[X[i].first][p];
                } else {
                    if (cc != x[X[i].first][p]) {
                        cout << "NO" << endl;
                        return 0;
                    }
                }
            }
            if (cc != 0) P = P + cc;
        }

        x[X[0].first] = P;
        for (int i = 1; i < X.size(); ++i) cz[X[i].first] = false;
    }
    
    vector<string> Z;
    for (int i = 0; i < N; ++i) {
        if (cz[i]) Z.push_back(x[i]);
    }

    for (int i = 0; i < Z.size(); ++i) {
        memset(cc, 0, sizeof(cc));
        for (int j = 0; j < Z[i].size(); ++j) {
            if (cc[Z[i][j] - 'a']) {
                cout << "NO" << endl;
                return 0;
            }
            cc[Z[i][j] - 'a'] = true;
        }
    }

    sort(Z.begin(), Z.end());

    for (int i = 0; i < Z.size(); ++i) cout << Z[i];
    cout << endl;

    return 0;
}