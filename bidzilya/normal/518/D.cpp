#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    double p;
    int t;
    cin >> n >> p >> t;

    vector<vector<double> > ans(t + 1, vector<double>(n + 1, 0.0));
    ans[0][n] = 1.0;
    for (int ct = 1; ct <= t; ++ct) {
        ans[ct][0] += ans[ct - 1][0];
        for (int pn = 1; pn <= n; ++pn) {
            ans[ct][pn] += ans[ct - 1][pn] * (1.0 - p);
            ans[ct][pn - 1] += ans[ct - 1][pn] * p;
        }
    }

    double gl_ans = 0.0;
    for (int pn = 0; pn <= n; ++pn) {
        gl_ans += ans[t][pn] * (n - pn);
    }

    cout << fixed << setprecision(15) << gl_ans << endl;

    return 0;
}