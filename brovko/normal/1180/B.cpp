#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], Max;

int f(int x)
{
    if(x>=0)
        return x;
    return -x-1;
}

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
    if(n%2==0)
    {
        for(int i=0;i<n;i++)
            cout << -f(a[i])-1 << ' ';
        return 0;
    }
    for(int i=0;i<n;i++)
        if(f(a[i])>f(a[Max]))
        Max=i;
    for(int i=0;i<n;i++)
        if(i==Max)
        cout << f(a[i]) << ' ';
    else cout << -f(a[i])-1 << ' ';
}