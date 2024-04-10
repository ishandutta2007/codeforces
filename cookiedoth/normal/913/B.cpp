#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 5000;
const ll MOD = 1e9 + 7;
int n, p[mx], sheet[mx], cnt[mx];
vector<int> g[mx];

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i + 1];
        p[i + 1]--;
        g[p[i + 1]].push_back(i + 1);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 0) {
            sheet[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (auto v1 : g[i]) {
            cnt[i] += sheet[v1];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (sheet[i] == 0 && cnt[i] < 3) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}