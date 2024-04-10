/**
 *  created: 05/09/2021, 18:14:47
**/

#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s >> n;
        int sum = 0;
        for (char c : s) {
            sum += c - '0';
        }
        vector<int> ans;
        if (sum >= n) {
            for (int i = 0; i + 1 < n; ++i) {
                for (int j = 0; j < s.size(); ++j) {
                    if (s[j] != '0') {
                        --s[j];
                        string x(s.size(), '0');
                        x[j] = '1';
                        ans.push_back(atoi(x.c_str()));
                        break;
                    }
                }
            }
            ans.push_back(atoi(s.c_str()));
        } else {
            multiset<int> q;
            for (int i = 0; i < s.size(); ++i) {
                for (char j = '0'; j < s[i]; ++j) {
                    q.insert(s.size() - 1 - i);
                }
            }
            while (q.size() < n) {
                auto it = q.upper_bound(0);
                assert(it != q.end());
                int val = *it;
                q.erase(it);
                if (q.size() + 10 <= n) {
                    for (int i = 0; i < 10; ++i) {
                        q.insert(val - 1);
                    }
                } else {
                    while (q.size() + 1 < n) {
                        q.insert(val - 1);
                    }
                    break;
                }
            }
            for (int x : q) {
                int val = 1;
                for (int i = 0; i < x; ++i) {
                    val *= 10;
                }
                ans.push_back(val);
            }
            int other = atoi(s.c_str()) - accumulate(ans.begin(), ans.end(), 0);
            if (other) {
                ans.push_back(other);
            }
        }
        assert(ans.size() == n);
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}