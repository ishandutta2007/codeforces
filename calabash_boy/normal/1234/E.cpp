#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N = 2e5 + 10;
int x[N];
ll ans[N];
vector<int> ind[N];
 
int pos(int n, int m) {
    if (n == m)
        return 0;
    else if (n < m)
        return n + 1;
    else
        return n;
}
 
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i = 0; i < m; i++) {
        if (i)
            ind[x[i - 1]].push_back(x[i]);
        if (i < m - 1)
            ind[x[i + 1]].push_back(x[i]);
    }
    for (int i = 1; i < m; i++)
        ans[0] += abs(pos(x[i], 0) - pos(x[i - 1], 0));
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1];
        for (int j = 0; j < ind[i].size(); j++) {
            ans[i] -= abs(pos(ind[i][j], i - 1) - pos(i, i - 1));
            ans[i] += abs(pos(ind[i][j], i) - pos(i, i));
        }
        for (int j = 0; j < ind[i - 1].size(); j++) {
            if (ind[i - 1][j] != i) {
                ans[i] -= abs(pos(ind[i - 1][j], i - 1) - pos(i - 1, i - 1));
                ans[i] += abs(pos(ind[i - 1][j], i) - pos(i - 1, i));
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}