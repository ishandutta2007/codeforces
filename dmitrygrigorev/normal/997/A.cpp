#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int g = 0;
    bool z = false;
    for (int i=0; i < n; i++){
        if (s[i] == '0'){
            if (!z) g++;
            z = true;
        }
        else z = false;
    }
    if (g==0){
        cout << 0;
        return 0;
    }
    cout << (g-1) * min(x, y) + y;
    return 0;
}