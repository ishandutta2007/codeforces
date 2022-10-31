#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a[300000];

int main() {
    
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ll ans = -a[n-1];
    for(int i = 0; i < n;++i) {
        ans += a[i]*(i+2);
    }
    cout << ans << "\n";
    
}