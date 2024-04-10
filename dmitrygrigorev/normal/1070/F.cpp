#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int N = 5007;
const int Q = 507;
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
    int cnt = 0;
    vector <vector <int> > a(4);
    for (int i = 0; i < n; i++) {
        string s;
        int k;
        cin >> s >> k;
        int x = 0;
        for (int j = 0; j < 2; j++) {
            x = x * 2 + s[j] - '0';
        }
        a[x].push_back(k);
    }
    for (int i = 0; i < 4; i++) {
        sort(a[i].rbegin(), a[i].rend());
    }
    int add = 0;
    for (int x : a[3]) {
        add += x;
    }
    int res = 0;
    for (int j = 1; j < 3; j++) {
        int now = 0;
        int cnt = a[3].size(), cnt1 = a[3].size();
        for (int i = 0; i < a[j].size(); i++) {
            now += a[j][i];
            cnt--;
            cnt1++;
        }
        int k = 0, l = 0;
        int v = 3 - j;
        while ((k < a[0].size() || l < a[v].size()) && cnt1)  {
            if (k == a[0].size()) {
                cnt1--;
                now += a[v][l++];
                cnt++;
                continue;
            }
            if (l == a[v].size()) {
                if (cnt <= 0) break;
                cnt1--;
                cnt--;
                now += a[0][k++];
                continue;
            }
            if (cnt <= 0 || a[v][l] > a[0][k]) {
                now += a[v][l++];
                cnt++;
                cnt1--;
            } else {
                now += a[0][k++];
                cnt--;
                cnt1--;
            }
        }
        if (cnt < 0) continue;
        res = max(res, now);
    }
    cout << res + add;
}