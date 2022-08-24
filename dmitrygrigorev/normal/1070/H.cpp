#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    map <string, int> cnt;
    map <string, string> any;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        set <string> now;
        int sz = s.size();
        for (int l = 0; l < sz; l++) {
            for (int len = 1; len <= sz; len++) {
                now.insert(s.substr(l, len));
            }
        }
        for (auto t : now) {
            cnt[t]++;
            any[t] = s;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (!cnt.count(s)) {
            cout << "0 -\n";
        } else {
            cout << cnt[s] << " " << any[s] << "\n";
        }
    }
}