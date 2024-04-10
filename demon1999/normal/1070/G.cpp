#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;
int a[101], n, m, her[101], num[101];
vector<pair<int, int> > pos;
vector<int> order1, order2;

bool is_ok1(int pos) {
    vector<int> dp(n + 1, 0), pr(n + 1, 0);
    dp[pos + 1] = 1;
    int lst = -1;
    for (int j = pos; j >= 0; j--) {
        int have = her[j];
        if (her[j] == 0) {
            continue;
        }
        lst = j;
        for (int p = j + 1; p <= pos + 1; p++) {
            if (dp[p]) {
                dp[j] = 1;
                pr[j] = p;
                break;
            }
            have += a[p];
            if (have < 0) break;
        }
    }
        order1.resize(0);
    if (lst > -1 && dp[lst]) {

        int we = lst;
        while (we != pos + 1) {
            order1.push_back(num[we]);
            we = pr[we];
        }
        reverse(order1.begin(), order1.end());
    }
    if (lst == -1 || dp[lst]) return true;
    return false;
}

bool is_ok2(int pos) {
    vector<int> dp(n + 1, 0), pr(n + 1, 0);
    dp[pos - 1] = 1;
    int lst = -1;
    for (int j = pos; j < n; j++) {
        int have = her[j];
        if (her[j] == 0) {
            continue;
        }
        lst = j;
        for (int p = j - 1; p >= pos - 1; p--) {
            if (dp[p]) {
                dp[j] = 1;
                pr[j] = p;
                break;
            }
            have += a[p];
            if (have < 0) break;
        }
    }
            order2.resize(0);
    if (lst > -1 && dp[lst]) {

        int we = lst;
        while (we != pos - 1) {
            order2.push_back(num[we]);
            we = pr[we];
        }
        reverse(order2.begin(), order2.end());
    }
    if (lst == -1 || dp[lst]) return true;
    return false;
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    pos.resize(m);
    forn (i, m) {
        cin >> pos[i].fi >> pos[i].se;
        pos[i].fi--;
        num[pos[i].fi] = i;
        her[pos[i].fi] = pos[i].se;
    }
    sort(pos.begin(), pos.end());
    forn (i, n) cin >> a[i];
    int we = pos[0].fi;
    forn (i, n) {
        int p = a[i];
        if (is_ok1(i) && is_ok2(i + 1)) {
            if (i >= we) {
                cout << i + 1 << "\n";
            } else {
                cout << min(i + 2, n) << "\n";
            }
            vector<int> use(m, 0);
            for (int v : order1) {
                use[v] = 1;
                cout << v + 1 << " ";
            }
            for (int q : order2) {
                use[q] = 1;
                cout << q + 1 << " ";
            }
            forn (i, m)
                if (use[i] == 0) cout << i + 1 << " ";
            cout << "\n";
        return 0;
        }
    }
    cout << -1;
    return 0;
}