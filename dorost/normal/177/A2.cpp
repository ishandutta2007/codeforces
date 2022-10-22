#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            if (i == n / 2 || j == n / 2 || i == j || i == n - j - 1){
                ans += x;
            }
        }
    }
    cout << ans;
}