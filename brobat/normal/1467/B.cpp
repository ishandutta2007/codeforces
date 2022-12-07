#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<int> &v, int i) {
    if(i == 0) return false;
    if(i == (int)v.size() - 1) return false;
    return (v[i] < v[i - 1] && v[i] < v[i + 1]) || (v[i] > v[i - 1] && v[i] > v[i + 1]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0 ; i < n; i++) {
            cin >> v[i];
        }
        int num = 0;
        for(int i = 1; i < n - 1; i++) {
            if((v[i] < v[i - 1] && v[i] < v[i + 1]) || (v[i] > v[i - 1] && v[i] > v[i + 1])) {
                num++;
            }
        }
        // cerr << num << '\n';
        int sub = 0;
        for(int i = 1; i < n - 1; i++) {
            int a = check(v, i - 1) + check(v, i) + check(v, i + 1);
            int x = v[i];
            v[i] = v[i - 1];
            int b = check(v, i - 1) + check(v, i) + check(v, i + 1);
            v[i] = x;
            // cout << i << " " << a << " " << b << '\n';
            sub = max(sub, a - b);
        }
        for(int i = 1; i < n - 1; i++) {
            int a = check(v, i - 1) + check(v, i) + check(v, i + 1);
            int x = v[i];
            v[i] = v[i + 1];
            int b = check(v, i - 1) + check(v, i) + check(v, i + 1);
            v[i] = x;
            // cout << i << " " << a << " " << b << '\n';
            sub = max(sub, a - b);
        }
        cout << num - sub << '\n';
    }
    
    return 0;
}