#include <bits/stdc++.h>

using namespace std;

int Count[500000];

int main() {
    int n, m, a;
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        cin>>a;
        Count[a] ++;
    }

    long long sum = 0;
    for(int i=1; i<=m; i++) {
        sum += 1LL * Count[i] * (n - Count[i]);
    }
    cout << sum / 2;

    return 0;
}