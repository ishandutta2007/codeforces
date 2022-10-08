//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()


void solve() {
    struct university {
        vector<int64_t> students, pref_sum;

        void add(int64_t s) {
            students.push_back(s);
        }

        void staff() {
            sort(all(students));
            int sz = students.size();
//            cerr << sz << endl;
            pref_sum.assign(sz + 1, 0);
            for (int i = 1; i <= sz; ++i) {
                pref_sum[i] = pref_sum[i - 1] + students[i - 1];
            }
        }

        int64_t get_segm(int k) {
            int sz = students.size();
//            cerr << k << " " << sz << " " << pref_sum.size() << endl;
            if (k > sz) return 0ll;
            int l = sz % k;
            int64_t sum = pref_sum.back() - pref_sum[l];
            return sum;
        }
    };
    map<int, university> mapa;
    int n;
    cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    vector<int64_t> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        mapa[u[i]].add(s[i]);
    }

    vector<pair<int, int>> v;
    for (auto &[i, u] : mapa) {
        u.staff();
        v.push_back({u.students.size(), i});
    }
    sort(all(v));

    for (int i = 1; i <= n; ++i) {
        int64_t ans = 0;
        for (int j = v.size() - 1; j >= 0 && v[j].first >= i; j--) {
            ans += mapa[v[j].second].get_segm(i);
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}