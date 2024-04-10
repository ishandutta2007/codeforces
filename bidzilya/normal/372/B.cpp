#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int max_n = 40;

int a[max_n][max_n];
int n, m, q;
int eg[max_n][max_n];
int e[max_n][max_n][max_n][max_n];
int ans[max_n][max_n][max_n][max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            a[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; ++i)
        eg[i][0] = (a[i][0] == 0);
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < m; ++j)
            if (a[i][j] == 1) {
                eg[i][j] = 0;
            } else {
                eg[i][j] = eg[i][j - 1] + 1;
            }
    for (int is = 0; is < n; ++is) 
        for (int js = 0; js < m; ++js)
            for (int ie = is; ie < n; ++ie)
                for (int je = js; je < m; ++je) {
                    int mn = min(je - js + 1, eg[ie][je]);
                    e[is][js][ie][je] = mn;
                    for (int i = ie - 1; i >= is; --i) {
                        mn = min(mn, min(je - js + 1, eg[i][je]));
                        e[is][js][ie][je] += mn;
                    }
                }
    for (int is = 0; is < n; ++is)
        for (int js = 0; js < m; ++js) 
            for (int ie = 0; ie < n; ++ie)
                for (int je = 0; je < m; ++je) {
                    if (ie > is)
                        ans[is][js][ie][je] += ans[is][js][ie - 1][je];
                    if (je > js)
                        ans[is][js][ie][je] += ans[is][js][ie][je - 1];
                    if (ie > is && je > js)
                        ans[is][js][ie][je] -= ans[is][js][ie - 1][je - 1];
                    ans[is][js][ie][je] += e[is][js][ie][je];
                }
    for (; q; --q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        cout << ans[a][b][c][d] << endl;
    }
    return 0;
}