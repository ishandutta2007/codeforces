#include <bits/stdc++.h>
using namespace std;

int n, x[200009], u[200009], a[200009];

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> x[i], u[x[i]] = 1, a[i] = x[i];
    
    set<int> cc;
    for (int i = 1; i <= n; ++ i) if (u[i] == 0) cc.insert(i);
        
    for (int i = 1; i <= n; ++ i) if (x[i] == 0) {
        if ((*cc.begin()) != i) x[i] = *cc.begin(), cc.erase(cc.begin());
        else if (*(prev(cc.end())) != i) {
            x[i] = *prev(cc.end());
            cc.erase(prev(cc.end()));
        }
        else {
            for (int j = 1; j <= n; ++ j) {
                if (a[j] == 0 && x[j] != 0 && x[j] != j) {
                    x[i] = i;
                    swap(x[i], x[j]);
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i) cout << x[i] << " "; cout << endl;
    return 0;
}