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

const int max_n = 16, inf = 1111111111;

int n, m, a[max_n][max_n];
string name[max_n];
map<string, int> q;

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> name[i];
        q[name[i]] = i;
    }
    while (m--) {
        string x, y;
        cin >> x >> y;
        a[q[y]][q[x]] = 1;
        a[q[x]][q[y]] = 1;
    }
    int ans = 0, ans_mask;
    for (int mask = 1; mask < (1 << n); ++mask) {
        int cnt = 0, f = 0;
        vector<int> q;
        for (int j = 0; j < n; ++j) {
            if (get_bit(mask, j)) {
                ++cnt;
                if (cnt > 1) {
                    for (int k = 0; k < q.size(); ++k) {
                        if (a[q[k]][j]) {
                            f = 1;
                            break;
                        }
                    }
                }
                q.push_back(j);
            }
        }
        if (f == 0 && ans < cnt) {
            ans = cnt;
            ans_mask = mask;
        }
    }
    cout << ans << endl;
    ans = 0;
    for (int i = 0; i < n; ++i) {
        if (get_bit(ans_mask, i)) {
            name[ans] = name[i];
            ++ans;
        }
    }
    sort(name, name + ans);
    for (int i = 0; i < ans; ++i) {
        cout << name[i] << endl;
    }
    return 0;
}