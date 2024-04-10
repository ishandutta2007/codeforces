#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    int ans = 0;
    
    for(int i = 1; i < n; i++)
        {
            if(a[i] + a[i - 1] < k)
            {
                ans += k - a[i] - a[i - 1];
                a[i] = k - a[i - 1];
            }
        }
        
    cout << ans << "\n";
    
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}