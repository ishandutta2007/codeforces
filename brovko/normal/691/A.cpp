#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int s = 0;
    
    for(int i = 0; i < n; i++)
        s += a[i];
    
    if(n == 1 && s == 1 || n > 1 && s == n - 1)
        cout << "YES";
    else cout << "NO";
}