#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n;
    cin >> n;
    int s[100];
    for (int i=0; i < 100; i++) s[i] = 0;
    for (int i=0; i < n; i++){
        int x;
        cin >> x;
        s[x-1]++;
    }
    int mx = 0;
    for (int i=0; i < 100; i++) mx = max(mx, s[i]);
    cout << mx;
    return 0;
}