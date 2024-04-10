#include<bits/stdc++.h>
using namespace std;
#define rep(x,l,r) for (int x = l;x<r;x++)
const int N = 1e5 + 5;
int vis[N];
int n, k;
vector<int> a;
int main() {
    cin >> n >> k;
    a.resize(n);
    rep(i, 0, n) cin >> a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > k)break;
        vis[i] = 1;
        ans++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > k)break;
        if (vis[i])break;
        ans++;
    }
    cout << ans << endl;
}