#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int x){
    for (int i=2; i*i <= x;i++){
        if (x % i == 0) return true;
    }
    return false;
}
signed main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int x = n;
    while (true){
        if (!check(x)) break;
        x++;
    }
    cout << x << " " << x << endl;
    cout << 1 << " " << 2 << " " << x-n+2 << endl;
    for (int i=3; i <= n; i++){
        cout << i-1 << " " << i << " " << 1 << endl;
    }
    m -= (n-1);
    for (int i=1; i <= n; i++){
        for (int j=1; j <= n; j++){
            if (i == j) continue;
            if (m == 0) return 0;
            if (abs(i-j) == 1) continue;
            if (j > i) continue;
            cout << i << " " << j << " " << 1000000000 << endl;
            m--;
        }
    }
    return 0;
}