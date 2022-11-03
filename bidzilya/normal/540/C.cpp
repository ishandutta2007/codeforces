#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char> > a(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    --si;
    --sj;
    int fi, fj;
    cin >> fi >> fj;
    --fi;
    --fj;
    vector<vector<int> > used(n, vector<int>(m, 0));
    used[si][sj] = 1;
    queue<int> qi, qj;
    qi.push(si);
    qj.push(sj);
    while (!qi.empty()) {
        int ci = qi.front();
        qi.pop();
        int cj = qj.front();
        qj.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = ci + dx[k];
            int nj = cj + dy[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                if (!used[ni][nj]) {
                    used[ni][nj] = 1;
                    if (a[ni][nj] != 'X') {
                        qi.push(ni);
                        qj.push(nj);
                    }
                }
            }
        }
    }
    int c = 0;
    for (int i = 0; i < 4; ++i) {
        int ni = fi + dx[i];
        int nj = fj + dy[i];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                a[ni][nj] != 'X') {
            ++c;
        }
    }
    if (fi == si && fj == sj) {
        if (c >= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    if (a[fi][fj] != 'X') {
        if (abs(fi - si) + abs(fj - sj) == 1 && c >= 1) {
            cout << "YES" << endl;
            return 0;
        }
        if (used[fi][fj] && c >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (used[fi][fj]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}