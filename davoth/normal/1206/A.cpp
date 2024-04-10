#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    sort(b,b+m);
    cout << a[n-1] << ' ' << b[m-1];
    return 0;
}