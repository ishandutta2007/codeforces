#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, sum = 0, a, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a;
        if (a == -1){
            if (sum == 0) {
                ans ++;
            }
            sum = max (0, sum - 1);
        }else {
            sum += a;
        }
    }
    cout << ans;
}