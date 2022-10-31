#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    
    int n, x, ans = 0;
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) {
        if(x%i == 0 && x/i <=n)
            ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}