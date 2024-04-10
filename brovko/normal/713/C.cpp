#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[3005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        a[i] -= i;
        
    int ans = 0;
    
    for(int i = 0; i < n; i++)
    {
        int Max = 0;
        
        for(int j = 0; j <= i; j++)
            if(a[j] > a[Max])
                Max = j;
        
        ans += a[Max] - a[i];
        
        a[Max] = a[i];
    }
    
    cout << ans;
}