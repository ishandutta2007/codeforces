#include <bits/stdc++.h>

using namespace std;

const int mx = 2000;
int n, m, k, a[mx][mx], si, sj;
char c;
queue<pair<int, int> > q;
vector<char> ans;

void relax(int i, int j, int val) {
    if (a[i][j] == -2) return;
    if (a[i][j] == -1) {
        a[i][j] = (val + 1);
        q.push(make_pair(i, j));
    }
    else {
        a[i][j] = min(a[i][j], val + 1);
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i <= (n + 1); ++i) {
        for (int j = 0; j <= (m + 1); ++j) {
            a[i][j] = -2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == '.')
                a[i][j] = -1;
            if (c == '*')
                a[i][j] = -2;
            if (c == 'X') {
                a[i][j] = 0;
                si = i;
                sj = j;
                q.push(make_pair(si, sj));
            }
        }
    }
    if ((a[si - 1][sj] == -2) && ((a[si + 1][sj] == -2)) && (a[si][sj - 1] == -2) && (a[si][sj + 1] == -2)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if ((k % 2) == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    while (not(q.empty())) {
        pair<int, int> p = q.front();
        q.pop();
        int ii = p.first;
        int jj = p.second;
        relax(ii - 1, jj, a[ii][jj]);
        relax(ii + 1, jj, a[ii][jj]);
        relax(ii, jj - 1, a[ii][jj]);
        relax(ii, jj + 1, a[ii][jj]);
    }
    while (k >= 0) {
        k--;
        if ((a[si+1][sj] != -2) && (a[si+1][sj] <= k)) {
            ans.push_back('D');
            si++;
            continue;
        }
        if ((a[si][sj-1] != -2) && (a[si][sj-1] <= k)) {
            ans.push_back('L');
            sj--;
            continue;
        }
        if ((a[si][sj+1] != -2) && (a[si][sj+1] <= k)) {
            ans.push_back('R');
            sj++;
            continue;
        }
        if ((a[si-1][sj] != -2) && (a[si-1][sj] <= k)) {
            ans.push_back('U');
            si--;
            continue;
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%c", ans[i]);
    }
    return 0;
}