#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    ll c;
    cin >> n >> c;
    ll a[n], i;
    for (i = 0; i < n; i++){
        cin >> a[i];
    }
    for (i = n - 1; i > 0; i--) {
        if (a[i] - a[i - 1] > c) {
            break;
        }
    }
    cout << n - i;
}