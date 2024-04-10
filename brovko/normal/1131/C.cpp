#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[105], L, R, b[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);

    L=1;
    R=n-1;
    b[0]=a[n-1];

    for(int i=n-2;i>=0;i--)
    {
        if(i%2)
        {
            b[L]=a[i];
            L++;
        }
        else
        {
            b[R]=a[i];
            R--;
        }
    }

    for(int i=0; i<n; i++)
        cout << b[i] << ' ';
}