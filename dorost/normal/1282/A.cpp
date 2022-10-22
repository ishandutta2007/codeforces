#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t;
    cin >> t;
    while (t--){
        int a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b){
            swap (a, b);
        }
        if (c < a){
            cout << max((b - a) - (max (0, c + r - a)), 0) << endl;
            continue;
        }
        if (c > b){
            cout << max((b - a) - max(0, b - (c - r)), 0) << endl;
            continue;
        }
        if (c + r >= b){
            if (c - r < a){
                cout << 0;
            }else {
                cout << max(c - r - a, 0);
            }
        }else {
            if (c - r <= a)
                cout << max(b - c - r, 0);
            else
                cout << max(b - a - (r + r), 0);
        }
        cout << endl;
    }
}