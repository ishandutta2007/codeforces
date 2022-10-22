#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n - 1; i++)
        cout << a[i] + a[i + 1] << ' ';
    
    cout << a[n - 1];
}