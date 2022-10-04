#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 30;
int n, a[mx], res[mx];
vector<pair<int, int> > v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; ++i) {
        res[v[i].second] = a[v[i + 1].second];
    }
    res[v[n - 1].second] = a[v[0].second];
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}