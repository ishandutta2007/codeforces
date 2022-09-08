/**
 *  created: 07/05/2021, 17:49:01
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

vector<int> hid{2, 3, 5, 1, 4};

int query(int t, int i, int j, int x) {
    cout << "? " << t << " " << i + 1 << " " << j + 1 << " " << x << endl;
    if (0) {
        if (t == 1) {
            return max(min(x, hid[i]), min(x + 1, hid[j]));
        } else {
            return min(max(x, hid[i]), max(x + 1, hid[j]));
        }
    }
    int res;
    cin >> res;
    return res;
}

int t, n;



int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> cands;
        if (n % 2) {
            cands.push_back(0);
        }
        for (int i = n % 2; i < n; i += 2) {
            int res = query(1, i, i + 1, n - 1);
            if (res >= n - 1) {
                cands.push_back(i);
                cands.push_back(i + 1);
            }
        }
        int pos = -1;
        for (int i : cands) {
            int other = 0;
            if (i == other) {
                ++other;
            }
            if (query(1, other, i, n - 1) == n) {
                pos = i;
                break;
            }
        }
        assert(pos != -1);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (i == pos) {
                ans.push_back(n);
            } else {
                ans.push_back(query(2, i, pos, 1));
            }
        }
        cout << "! ";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}