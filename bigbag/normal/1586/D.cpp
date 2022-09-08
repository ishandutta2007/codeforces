/**
 *  created: 17/10/2021, 14:38:09
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;
const bool debug = 0;

int n, a[max_n];
vector<int> hid{1, 2, 3, 4, 5};

int ask(const vector<int> &add) {
    cout << "?";
    for (int x : add) {
        cout << " " << x;
    }
    cout << endl;
    if (debug) {
        vector<int> s = hid;
        for (int i = 0; i < s.size(); ++i) {
            s[i] += add[i];
        }
        int res = -1;
        for (int i = 0; i < s.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < s.size(); ++j) {
                cnt += s[i] == s[j];
            }
            if (cnt > 1) {
                res = i;
                break;
            }
        }
        cout << "res = " << res << endl;
        return res;
    }
    int res;
    cin >> res;
    --res;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (debug) {
        n = hid.size();
    } else {
        cin >> n;
    }
    int mx = n;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i]) {
            continue;
        }
        vector<int> v(n, 1);
        vector<int> elems{i};
        a[i] = inf;
        for (int add = 1; ; ++add) {
            ++v[i];
            if (v[i] > n) {
                break;
            }
            int pos = ask(v);
            if (pos == -1 || a[pos]) {
                break;
            }
            elems.push_back(pos);
        }
        //cout << i << ": " << elems.size() << endl;
        while (!elems.empty()) {
            a[elems.back()] = mx--;
            elems.pop_back();
        }
    }
    cout << "!";
    for (int i = 0; i < n; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}