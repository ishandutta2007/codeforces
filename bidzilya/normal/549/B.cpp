#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<char> > a(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[j]) {
                continue;
            }
            if (b[j] != 0) {
                continue;
            }
            used[j] = true;
            for (int t = 0; t < n; ++t) {
                if (a[j][t] == '1') {
                    --b[t];
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (used[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}