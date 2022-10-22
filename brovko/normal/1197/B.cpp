#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[300005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    int Max=0;
    for(int i=0;i<n;i++)
        if(a[i]>a[Max])
            Max=i;
    
    for(int i=0;i<Max-1;i++)
        if(a[i]>=a[i+1])
    {
        cout << "NO";
        return 0;
    }
    
    for(int i=Max;i<n-1;i++)
        if(a[i]<=a[i+1])
    {
        cout << "NO";
        return 0;
    }
    
    cout << "YES";
}