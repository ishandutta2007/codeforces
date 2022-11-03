#include <bits/stdc++.h>
using namespace std;

const char kPlayer = 'o';
const char kBeated = 'x';
const char kFree = '.';

int main()
{
    //freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<int> > cnt(2 * n - 1, vector<int>(2 * n - 1, 0));
    
    int aps = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == kPlayer) {
                ++aps;
                for (int di = -(n - 1); di <= n - 1; ++di) {
                    for (int dj = -(n - 1); dj <= n - 1; ++dj) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (!(ni >= 0 && ni < n && nj >= 0 && nj < n) || 
                             (a[ni][nj] == kPlayer || a[ni][nj] == kBeated)) {
                            ++cnt[di + n - 1][dj + n - 1];
                        }
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == kBeated) {
                bool good = false;
                for (int ni = 0; ni < n; ++ni) {
                    for (int nj = 0; nj < n; ++nj) {
                        if (a[ni][nj] == kPlayer) {
                            int di = i - ni;
                            int dj = j - nj;
                            if (cnt[di + n - 1][dj + n - 1] == aps) {
                                good = true;
                            }
                        }
                    }
                }
                if (!good) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    
    cout << "YES" << endl;
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            if (i == n - 1 && j == n - 1) {
                cout << kPlayer;
            } else if (cnt[i][j] == aps) {
                cout << kBeated;
            } else {
                cout << kFree;
            }
        }
        cout << endl;
    }

    return 0;
}