#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long r, h;
    cin >> r >> h;
    
    if (h % r == 0) {
        cout << 2 * (h / r) + 1 << endl;
    } else {
        long long c = h / r;
    
        long long ans = 2 * c;
        
        if (2 * (h - c * r) >= r) {
            ans += 2;
            if (3 * r * r <= 4 * (c * r - h) * (c * r - h)) {
                ++ans;
            }
        } else {
            ++ans;
        }
    
        cout << ans << endl;
    }
    
    return 0;
}