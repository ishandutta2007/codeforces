#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int calculate (int n, int m){
    return n + n + m + m - 4;
}
int main(){
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        ans += calculate (n , m);
        n -= 4;
        m -= 4;
    }
    cout << ans;
}