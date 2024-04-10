#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while (q--){
        int n;
        cin >> n;
        n *= 4;
        int a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort (a, a + n);
        bool f = true;
        for (int i = 0; i < n; i += 2){
            if (a[i] != a[i + 1]){
                f = false;
                break;
            }
        }
        if (f == false){
            cout << "NO" << endl;
            continue;
        }
        ll b[n / 2];
        for (int i = 0; i < n; i += 2){
            b[i / 2] = a[i];
        }
        n /= 2;
        ll ans = b[0] * b[n - 1];
        for (int i = 1; i < n; i++){
            if (b[i] * b[n - i - 1] != ans){
                f = false;
                break;
            }
        }
        if (f == false){
            cout << "NO" << endl;
        }else
            cout << "YES" << endl;
    }
}