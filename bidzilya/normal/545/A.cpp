#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        bool good = true;
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1 || a[i][j] == 3) {
                good = false;
                break;
            }
        }
        if (good) {
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