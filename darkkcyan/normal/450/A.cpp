#include<bits/stdc++.h>
using namespace std;

const int maxn = 111;
int n, m;
int a[maxn];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    int cur = 0;
    int cnt = n;
    while (cnt > 0) {
        if (a[cur] > 0) {
            a[cur] -= m;
            if (a[cur] <= 0) --cnt;
        }
        ++cur;
        if (cur == n) cur = 0;
    }
    
    if (cur == 0) cout << n;
    else cout << cur;

    return 0;
}