/**
 *  created: 28/02/2021, 18:17:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, inf = 1000111222;

int t, n;

int query(const vector<int> &a, const vector<int> &b) {
    cout << "? " << a.size() << " " << b.size() << "\n";
    for (int x : a) {
        cout << x + 1 << " ";
    }
    cout << "\n";
    for (int y : b) {
        cout << y + 1 << " ";
    }
    cout << endl;
    int res = 0;
    cin >> res;
    return res;
}

void write(vector<int> v) {
    cout << "! " << v.size() << " ";
    for (int x : v) {
        cout << x + 1 << " ";
    }
    cout << endl;
}

vector<int> ans;

void solve(int l, int r, int pos, bool ok) {
    if (l == r && ok) {
        return;
    }
    int mid = (l + r) / 2;
    vector<int> b;
    for (int i = l; i <= mid; ++i) {
        b.push_back(i);
    }
    vector<int> a{pos};
    int res = query(a, b);
    if (l == r) {
        if (!res) {
            ans.push_back(l);
        }
        return;
    }
    if (res) {
        for (int i = mid + 1; i <= r; ++i) {
            ans.push_back(i);
        }
        solve(l, mid, pos, 1);
    } else {
        for (int i = l; i <= mid; ++i) {
            ans.push_back(i);
        }
        solve(mid + 1, r, pos, ok);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        int last, pos = -1;
        for (int i = 0; i < n; ++i) {
            vector<int> a{i}, b;
            for (int j = i + 1; j < n; ++j) {
                if (i != j) {
                    b.push_back(j);
                }
            }
            last = query(a, b);
            if (last != 0) {
                pos = i;
                break;
            }
        }
        int our = 1, other = 0;
        ans.clear();
        for (int i = pos + 1; i + 1 < n; ++i) {
            vector<int> a{pos}, b{i};
            int res = query(a, b);
            if (res == 0) {
                ans.push_back(i);
            } else {
                our += res == 1;
                other += res == -1;
            }
        }
        if (our - other - 1 == last) {
            ans.push_back(n - 1);
        }
        if (pos) {
            solve(0, pos - 1, pos, 0);
        }
        write(ans);
    }
    return 0;
}