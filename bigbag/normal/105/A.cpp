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

const int max_n = 22, inf = 1111111111;

int n, m, k, x;
string s;
set<string> q;
vector<pair<string, int> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> s;
    k = (s[2] - '0') * 10 + s[3] - '0';
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s >> x;
        x *= k;
        x /= 100;
        if (x < 100) {
            continue;
        }
        ans.push_back(make_pair(s, x));
        q.insert(s);
    }
    while (m--) {
        string s;
        cin >> s;
        if (!q.count(s)) {
            ans.push_back(make_pair(s, 0));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}