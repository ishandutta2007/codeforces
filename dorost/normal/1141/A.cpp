#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m, ans = 0;
    cin >> n >> m;
    if (m % n){
        cout << -1;
        return 0;
    }
    int x = m / n;
    while (x % 2 == 0){
        x /= 2;
        ans ++;
    }
    while (x % 3 == 0){
        x /= 3;
        ans ++;
    }
    if (x == 1){
        cout << ans;
    }else
        cout << -1;
}