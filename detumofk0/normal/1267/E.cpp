#include<bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
int s[N];
int a[N][N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    if(fopen("inp", "r")) freopen("inp", "r", stdin);

    cin >> m >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            s[j] += a[i][j];
        }
    }


    vector < int > ans(10000, -1);

    for(int i = 1; i < m; ++i) {
        vector < int > rows;
        for(int j = 1; j <= n; ++j) rows.push_back(j);
        sort(rows.begin(), rows.end(), [&](int x, int y){
            return a[x][m] - a[x][i] > a[y][m] - a[y][i];
        });

        vector < int > ret;

        int d = s[i] - s[m];

        if(d >= 0) {
            cout << 0 << endl;
            return 0;
        }

        for(int r : rows) {
            d += a[r][m] - a[r][i];
            ret.push_back(r);
            if(d >= 0) {
                if(ans.size() > ret.size()) ans = ret;
            }
        }
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";

    return 0;
}