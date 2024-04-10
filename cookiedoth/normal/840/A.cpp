#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

const int mx = 500000;
int n;
vector<int> a, ans;
vector<pair<int, int> > b;

int main()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ans[b[i].second] = a[n - 1 - i];
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}