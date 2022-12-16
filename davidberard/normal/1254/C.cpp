#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n;

vector<int> above;
vector<int> below;

vector<int> reorder(int a, int b, vector<int> in) {
    vector<ll> h(n+1, 0);
    vector<pii> ord;
    for (auto& x : in) {
        cout << 1 << " " << a << " " << b << " " << x << endl;
        cin >> h[x];
        assert(h[x] != 0);
        ord.push_back(pii(h[x], x));
    }
    sort(ord.begin(), ord.end());
    bool have_ctr = false;
    pii ctr;
    vector<pii> left, right;
    if (ord.size()) {
        have_ctr = true;
        ctr = ord.back(); ord.pop_back();

        for (auto& p : ord) {
            ll x = p.second;
            ll h = p.first;

            cout << 2 << " " << a << " " << ctr.second << " " << x << endl;
            int sgn;
            cin >> sgn;
            if (sgn == 1) {
                left.emplace_back(h, x);
            } else if (sgn == -1) {
                right.emplace_back(h, x);
            } else {
                assert(false);
            }
        }
        sort(left.begin(), left.end());
        reverse(left.begin(), left.end());
        sort(right.begin(), right.end());
    }
    vector<int> ans;
    ans.push_back(b);
    for (auto& p : right) {
        ans.push_back(p.second);
    }
    if (have_ctr) {
        ans.push_back(ctr.second);
    }
    for (auto& p : left) {
        ans.push_back(p.second);
    }
    ans.push_back(a);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=3; i<=n; ++i) {
        cout << 2 << " " << 1 << " " << 2 << " " << i << endl;
        int sgn;
        cin >> sgn;
        if (sgn == 1) {
            above.push_back(i);
        } else if (sgn == -1) {
            below.push_back(i);
        } else {
            assert(false);
        }
    }
    above = reorder(1, 2, above);
    below = reorder(2, 1, below);
    above.pop_back();
    below.pop_back();
    cout << "0 ";
    for (auto& x : below) {
        cout << x << " ";
    }
    for (auto& x : above) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}