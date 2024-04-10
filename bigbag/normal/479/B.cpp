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

const int max_n = 111, inf = 1111111111;

int n, k, a[max_n];
set<pair<int, int> > q;
vector<pair<int, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        q.insert(make_pair(a[i], i));
    }
    while (k--) {
        pair<int, int> mn = *q.begin();
        pair<int, int> mx = *q.rbegin();
        if (mx.first - mn.first > 1) {
            q.erase(mn);
            q.erase(mx);
            --mx.first;
            ++mn.first;
            q.insert(mn);
            q.insert(mx);
            ans.push_back(make_pair(mx.second, mn.second));
        } else break;
    }
    pair<int, int> mn = *q.begin();
    pair<int, int> mx = *q.rbegin();
    cout << mx.first - mn.first << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    return 0;
}