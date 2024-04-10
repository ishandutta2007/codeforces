#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    
    for (int i = n - 2; i >= 0; --i)
        a[i] += a[i + 1];

    int sum = a[0];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < k; ++i) {
        sum += a[n - i];
    }
    cout << sum << endl;

    return 0;
}