#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n1, n2, k1, k2;

    cin >> n1 >> n2 >> k1 >> k2;

    vector<vector<int> > dp1(n1 + 1, vector<int>(n2 + 1));
    vector<vector<int> > dp2(n1 + 1, vector<int>(n2 + 1));

    dp1[0][0] = 0;
    dp2[0][0] = 0;

    for (int i = 1; i <= n1; ++i) {
        dp1[i][0] = 1;
        dp2[i][0] = 0;
    }

    for (int j = 1; j <= n2; ++j) {
        dp1[0][j] = 0;
        dp2[0][j] = 1;
    }

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            dp1[i][j] = 0;
            for (int k = 1; k <= k1; ++k) {
                if (i - k >= 0 && dp2[i - k][j] == 0) {
                    dp1[i][j] = 1;
                }
            }
            dp2[i][j] = 0;
            for (int k = 1; k <= k2; ++k) {
                if (j - k >= 0 && dp1[i][j - k] == 0) {
                    dp2[i][j] = 1;
                }
            }
        }
    }

    if (dp1[n1][n2]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }


    return 0;
}