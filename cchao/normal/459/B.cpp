#include <bits/stdc++.h>
using namespace std;

int a[200010], n, mi, ma;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(i == 0 || a[i] < mi) mi = a[i];
        if(i == 0 || a[i] > ma) ma = a[i];
    }
    long long aa = 0, bb = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == mi) aa++;
        if(a[i] == ma) bb++;
    }

    if(mi == ma) cout << 0 << ' ' << aa * (aa - 1) / 2;
    else cout << ma - mi << ' ' << aa * bb << endl;
    return 0;
}