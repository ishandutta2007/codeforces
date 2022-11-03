#include <bits/stdc++.h>
using namespace std;

vector<string> a;
vector<int> out, in;
int n;

inline int GetC2(int n)
{
    return n * (n - 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    int all = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '1') {
                ++all;
            }
        }
    }

    out.resize(n);
    in.resize(n);
    for (int i = 0; i < n; ++i) {
        out[i] = in[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '1') {
                ++out[i];
            }
            if (a[i][j] == '0' && j != i) {
                ++in[i];
            }
        }
    }

    for (int v = 0; v < n; ++v) {
        int cd = GetC2(out[v]);
        int cdc = 0;
        for (int u = 0; u < n; ++u) {
            if (u != v) {
                if (a[v][u] == '1') {
                    cdc += out[u];
                }
            }
        }
        int cc = cdc - cd;
        if (cc > 0) {
            for (int v1 = 0; v1 < n; ++v1) {
                for (int v2 = 0; v2 < n; ++v2) {
                    if (a[v1][v2] == '1' && a[v2][v] == '1' && a[v][v1] == '1') {
                        cout << v1 + 1 << " " << v2 + 1 << " " << v + 1 << endl;
                        return 0;
                    }
                }
            }
            cout << "FAIL" << endl;
        }
    }

    cout << -1 << endl;

    return 0;
}