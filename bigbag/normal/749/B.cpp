#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 5, inf = 1011111111;

int x[max_n], y[max_n], p[max_n];
vector<pair<int, int> > ans;

void proc() {
    for (int i = 0; i < 3; ++i) {
        p[i] = i;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    proc();
    do {
        int xx = x[p[2]] + x[p[0]] - x[p[1]];
        int yy = y[p[2]] + y[p[0]] - y[p[1]];
        if (x[p[0]] - xx == x[p[1]] - x[p[2]] && y[p[0]] - yy == y[p[1]] - y[p[2]]) {
            ans.push_back(make_pair(xx, yy));
        }
    } while (next_permutation(p, p + 3));

    proc();
    do {
        int xx = x[p[2]] + x[p[0]] - x[p[1]];
        int yy = y[p[2]] + y[p[0]] - y[p[1]];
        if (x[p[1]] - xx == x[p[0]] - x[p[2]] && y[p[1]] - yy == y[p[0]] - y[p[2]]) {
            ans.push_back(make_pair(xx, yy));
        }
    } while (next_permutation(p, p + 3));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}