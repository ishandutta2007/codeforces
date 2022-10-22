#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], s;

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
    sort(a, a+n);
    for(int i=0;i<n-1;i++)
        s+=a[i];
    if(a[n-1]>s)
    {
        cout << "NO";
        return 0;
    }
    s+=a[n-1];
    if(s%2==0)
        cout << "YES";
    else cout << "NO";
}