#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

char t[1010][1010];
int used[1010][1010];

int n, m;
void go(queue<pair<int, int>>& och, queue<pair<int, int> >& coch, int cl) {
    while (!och.empty()) {
        int x, y;
        x = och.front().first;
        y = och.front().second;
        for (int i = x; i < n; ++i) {
            if (t[i][y] == '*')
                break;
            if (!(used[i][y] & cl)) {
                used[i][y] |= cl;
                coch.push({i, y});
            }
        }
        och.pop();
        for (int i = x; i >= 0; --i) {
            if (t[i][y] == '*')
                break;
            if (!(used[i][y] & cl)) {
                used[i][y] |= cl;
                coch.push({i, y});
            }
        }
        for (int j = y; j < m; ++j) {
            if (t[x][j] == '*')
                break;
            if (!(used[x][j] & cl)) {
                used[x][j] |= cl;
                coch.push({x, j});
            }
        }
        for (int j = y; j >= 0; --j) {
            if (t[x][j] == '*')
                break;
            if (!(used[x][j] & cl)) {
                used[x][j] |= cl;
                coch.push({x, j});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    queue<pair<int, int> > och1;
    queue<pair<int, int> > och2;
    queue<pair<int, int> > och3;
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> t[i][j];
            if (t[i][j] == 'S')
                used[i][j] = 1, och1.push({i, j});
            if (t[i][j] == 'T')
                used[i][j] = 2, och2.push({i, j});
        }
    }
    go(och1, och3, 1);
    go(och2, och1, 2);
    go(och3, och1, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j] == 3) {
                cout << "YES\n";
                return;
            }
//            cout << used[i][j];
        }
//        cout << endl;
    }
    cout << "NO\n";
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}