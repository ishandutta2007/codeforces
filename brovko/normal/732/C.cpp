#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    
    int Max = max(a, max(b, c));
    
    int ans = 0;
    
    if(a != Max)
        ans += Max - 1 - a;
    
    if(b != Max)
        ans += Max - 1 - b;
        
    if(c != Max)
        ans += Max - 1 - c;
    
    cout << ans;
}