#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>


using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    int len = 0;
    vector<string> strs(n);
    vector<vector<int> > pos(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> strs[i];
        cin >> k;
        pos[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> pos[i][j];
            len = max(len, (int) (pos[i][j] - 1 + strs[i].size()));
        }
    }
    string ans(len, ' ');
    vector<int> rpos(len, -1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < pos[i].size(); ++j)
            if (rpos[pos[i][j] - 1] == -1 || strs[rpos[pos[i][j] - 1]].size() < strs[i].size())
                rpos[pos[i][j] - 1] = i;
    }
    int rb = -1;
    int p = 0;
    for (long long i = 0; i < len; ++i) {
        if (rpos[i] >= 0 && rb < (long long) (strs[rpos[i]].size() + i - 1))
            rb = strs[rpos[i]].size() + i - 1, p = rpos[i];
//        cout << p << ' ' << rb << endl;
        if (rb >= i)
            ans[i] = strs[p][strs[p].size() - (rb - i) - 1];
        else
            ans[i] = 'a';
    }
    cout << ans << endl;
}


int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}