#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int INF = 0x3f3f3f3f;
const int N = 100100;
int a[N]; // val
int w[N]; // reverse map
int bi[N]; // largest increasing
int pi[N]; // parent increasing
vector<int> bd[N]; // decreasing sequences
int n;

int lis() {
    memset(bi, 0, sizeof(int)*(n+1));
    int sz=0;
    for (int i=1; i<=n; ++i) {
        if (a[i] == 0) continue;
        int lo=0, hi=sz;
        while (lo<hi) {
            int m=(lo+hi+1)/2;
            if (bi[m] < a[i]) {
                lo = m;
            } else {
                hi = m-1;
            }
        }
        pi[a[i]] = bi[lo];
        bi[lo+1] = a[i];
        if (lo+1 > sz) {
            sz = lo+1;
            bd[sz].clear();
        }
        bd[lo+1].push_back(a[i]);
    }
    return sz;
}

vector<int> get(int b[], int p[], int k) {
    int x = b[k];
    
    vector<int> tmp;
    while (x != 0 && x != INF) {
        tmp.push_back(x);
        a[w[x]] = 0;
        x = p[x];
    }
    reverse(tmp.begin(), tmp.end());
    assert(tmp.size() == k);

    return tmp;
}

void solve() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        w[a[i]] = i;
    }

    vector<vector<int>> ans;
    int k = n;
    while (k) {
        int isz = lis();

        if ((ll)(isz)*(isz+1)/2 > k) {
            ans.push_back(get(bi, pi, isz));
            k -= isz;
        } else {
            for (int i=1; i<=isz; ++i) {
                ans.push_back(bd[i]);
                k -= ans.back().size();
            }
            assert(k == 0);
        }
    }

    cout << ans.size() << "\n";
    for (auto& x : ans) {
        cout << x.size() << " ";
        for (auto& y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}