#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x, a, ans = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a;
        ans += a;
    }
    cout << (abs(ans) + x - 1) / x;
}