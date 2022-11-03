#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    const string kFace = "face";

    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n && j + 1 < m) {
                int cc = 0;
                for (int k = 0; k < 4; ++k) {
                    char c = kFace[k];
                    if (a[i][j] == c || a[i + 1][j] == c || a[i][j + 1] == c || a[i + 1][j + 1] == c) {
                        ++cc;
                    }
                }
                if (cc == 4) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}