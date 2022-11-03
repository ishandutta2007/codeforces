#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    /*
    freopen("input.txt", "w", stdout);
    const int N = 1e3;
    const int M = 44;
    cout << N + M << endl;
    for (int i = 0; i < N; ++i) {
        cout << 1 << " ";
    }
    int n0 = 1;
    int n1 = 1;
    cout << n0 << " " << n1 << " ";
    for (int i = 2; i < M; ++i) {
        int n = n0 + n1;
        cout << n << " ";
        n0 = n1;
        n1 = n;
    }
    cout << endl;
    return 0;
    */
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> buf = a;
    sort(buf.begin(), buf.end());
    buf.resize(unique(buf.begin(), buf.end()) - buf.begin());
    unordered_map<long long, int> mp;
    int m = buf.size();
    for (int i = 0; i < m; ++i) {
        mp[buf[i]] = i;
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = mp[a[i]];
    }

    vector<vector<int>> nxt(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            long long val = buf[i] + buf[j];
            const auto& itr = mp.find(val);
            if (itr == mp.end()) {
                nxt[i][j] = -1;
            } else {
                nxt[i][j] = itr->second;
            }
            nxt[j][i] = nxt[i][j];
        }
    }

    vector<int> count(m, 0);
    for (int i = 0; i < n; ++i) {
        ++count[b[i]];
    }

    vector<int> deleted;
    deleted.reserve(n);

    int nullCount = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++nullCount;
        }
    }

    int result = 0;

    if (nullCount >= 2) {
        result = max(result, nullCount);
    }

    for (int i = 0; i < n; ++i) {
        --count[b[i]];
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (buf[b[i]] == 0 && buf[b[j]] == 0) {
                continue;
            }
            --count[b[j]];
            deleted.push_back(b[j]);
            int n0 = b[i];
            int n1 = b[j];
            int curResult = 2;
            while (true) {
                int nn = nxt[n0][n1];

                if (nn == -1 || count[nn] == 0) {
                    break;
                }

                --count[nn];
                deleted.push_back(nn);
                n0 = n1;
                n1 = nn;
                ++curResult;
            }
            result = max(result, curResult);
            for (int x : deleted) {
                ++count[x];
            }
            deleted.clear();
        }
        ++count[b[i]];
    }

    cout << result << endl;

    return 0;
}