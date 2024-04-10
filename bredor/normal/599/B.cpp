
#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > findexes(n + 1);

    for (int i = 1; i <= n; ++i) {
        int f;
        cin >> f;
        findexes[f].push_back(i);
    }

    vector<int> b(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }

    vector<int> a(m + 1, 0);

    for (int i = 1; i <= m; ++i) {
        int sz = findexes[b[i]].size();
        if (sz == 0) {
            cout << "Impossible";
            return 0;
        }
        a[i] = findexes[b[i]][0];
    }

    for (int i = 1; i <= m; ++i) {
        int sz = findexes[b[i]].size();
        if (sz > 1) {
            cout << "Ambiguity";
            return 0;
        }
    }

    cout << "Possible\n";

    for (int i = 1; i <= m; ++i) {
        cout << a[i] << " ";
    }

    return 14 / 88;

}