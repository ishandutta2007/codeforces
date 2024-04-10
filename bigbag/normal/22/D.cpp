#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

struct state {
    int x, t, num;
    bool operator < (const state &a) const {
        return x < a.x || x == a.x && t < a.t;
    }
};


state make_state(int x, int t, int num) {
    state ret;
    ret.x = x;
    ret.t = t;
    ret.num = num;
    return ret;
}

int n, f[max_n], l[max_n], r[max_n];
vector <int> ans;
vector <state> a;

int main() {
    //freopen("output.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        if (l[i] > r[i]) {
            swap(l[i], r[i]);
        }
        a.push_back(make_state(l[i], 1, i));
        a.push_back(make_state(r[i], 2, i));
    }
    sort(a.begin(), a.end());
    vector <int> v, nul;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].t == 1) {
            v.push_back(a[i].num);
        } else {
            if (f[a[i].num] == 0) {
                ans.push_back(a[i].x);
                for (int j = 0; j < v.size(); ++j)  {
                    f[v[j]] = 1;
                }
                v = nul;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}