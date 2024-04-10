#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int ans;
    if(n < 1200) ans = 1200;
    else if(n < 1400) ans = 1400;
    else if(n < 1600) ans = 1600;
    else if(n < 1900) ans = 1900;
    else if(n < 2100) ans = 2100;
    else if(n < 2300) ans = 2300;
    else if(n < 2400) ans = 2400;
    else if(n < 2600) ans = 2600;
    else ans = 3000;
    cout << ans << "\n";
    return 0;
}