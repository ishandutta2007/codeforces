#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, x1, y1, x2, y2;
map<pair<int, int>, int> m;

bool is_in(int x, int y) {
    return x == 0 && y >= 0 && y <= n || x == n && y >= 0 && y <= n || y == 0 && x >= 0 && x <= n || y == n && x >= 0 && x <= n;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x1 >> y1 >> x2 >> y2;
    queue<pair<int, int> > q;
    q.push(make_pair(x1, y1));
    m[make_pair(x1, y1)] = 0;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        //cout << v.first << ' ' << v.second << endl;
        for (int i = 0; i < 4; ++i) {
            int a = v.first + dx[i], b = v.second + dy[i];
            if (is_in(a, b) && !m.count(make_pair(a, b))) {
                q.push(make_pair(a, b));
                m[make_pair(a, b)] = m[make_pair(v.first, v.second)] + 1;
            }
        }
    }
    cout << m[make_pair(x2, y2)] << endl;
    return 0;
}