#pragma GCC optimize("O3")
    #include <bits/stdc++.h>
    #define pb push_back
    #define ll long long
    #define int ll
    using namespace std;
    int N, Q;
    static const int k = 450;
    vector<int> v;
    vector<int> cc(1000010);
    vector<array<int, 3> > q;
    vector<int> ans(200010);
    int l = 0, r = -1;
    int pp = 0;
    void add(int p) {
        pp -= cc[v[p]] * cc[v[p]] * v[p];
        cc[v[p]]++;
        pp += cc[v[p]] * cc[v[p]] * v[p];
    }
    void rem(int p) {
        pp -= cc[v[p]] * cc[v[p]] * v[p];
        cc[v[p]]--;
        pp += cc[v[p]] * cc[v[p]] * v[p];
    }
    signed main() {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }
        for (int i = 0; i < Q; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            q.pb({a, b, i});
        }
        sort(q.begin(), q.end(), [](auto &a, auto &b) {
            if (a[0] / k == b[0] / k && a[0]/k%2==0) return a[1] < b[1];
            if (a[0] / k == b[0] / k) return a[1] > b[1];
            return a[0] / k < b[0] / k;
        });
        for (auto x : q) {
            while (l > x[0]) {
                add(l - 1);
                l--;
            }
            while (r < x[1]) {
                add(r + 1);
                r++;
            }
            while (l < x[0]) {
                rem(l);
                l++;
            }
            while (r > x[1]) {
                rem(r);
                r--;
            }
            ans[x[2]] = pp;
        }
        for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
    }