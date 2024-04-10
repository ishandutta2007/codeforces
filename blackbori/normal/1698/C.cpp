#include <bits/stdc++.h>

using namespace std;

void tc() {
    vector<int> V;
    int n, a = 0, b = 0, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t > 0) a++;
        if (t < 0) b++;
        if (t == 0) c++;
        
        if (t != 0) {
            V.push_back(t);
        }
        else {
            if (c == 1) {
                V.push_back(t);
            }
        }
    }
    if (a >= 3 || b >= 3) {
        cout << "NO\n";
        return;
    }
    
    n = V.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = V[i] + V[j] + V[k];
                int f = 0;
                for (int l = 0; l < n; l++) {
                    if (a == V[l]) {
                        f = 1; break;
                    }
                }
                if (f == 0) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        tc();
    }
    
    return 0;
}