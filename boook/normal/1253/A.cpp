#include <bits/stdc++.h>
using namespace std;

const int maxn = 100090;

int t, n, a[maxn], b[maxn];

int main(){
    cin.tie(0), cout.sync_with_stdio(0);
    
    cin >> t;

    for (int times = 0; times < t; times ++) {
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n; i ++) cin >> b[i];
        for (int i = 1; i <= n; i ++) a[i] = b[i] - a[i];

        int ql = n + 1, qr = -1, ok = 1;
        for (int i = 1; i <= n; i ++) if(a[i] != 0) {
            ql = min(ql, i);
            qr = max(qr, i);
        }
        if (a[ql] < 0) ok = 0;
        if (ql == n + 1) ;
        else {
            for (int i = ql; i <= qr; i ++) 
                if (a[i] != a[ql]) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
        
        for (int i = 1; i <= n; i ++) a[i] = 0;
    }
    return 0;
}