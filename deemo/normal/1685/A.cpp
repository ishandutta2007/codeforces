#include <bits/stdc++.h> 

using namespace std;

const int MAXN = 2e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        int n; cin >> n;
        vector<int> vec(n);
        map<int, int> cnt;
        for (int i = 0; i < n; i++)
            cin >> vec[i], cnt[vec[i]]++;

        if (n&1) {
            cout << "NO\n";
            continue;
        }

        sort(vec.begin(), vec.end());
        vector<int> ans;
        for (int i = 0; i < n/2; i++)
            ans.push_back(vec[i]), ans.push_back(vec[i+n/2]);

        bool failed = false;
        for (int i = 0; i < n; i++) {
            int nxt = i+1 == n? 0: i+1;
            int prv = i==0? n-1: i-1;
            failed |= !(ans[i] > ans[prv] && ans[i] > ans[nxt] || ans[i] < ans[prv] && ans[i] < ans[nxt]);
        }
        if (failed)
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (auto x: ans)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}