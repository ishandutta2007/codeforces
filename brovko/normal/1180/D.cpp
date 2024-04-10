#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh
#define endl "\n"

using namespace std;

int n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<m/2;i++)
    {
        for(int j=0;j<n;j++)
            cout << j+1 << ' ' << i+1 << endl << n-j << ' ' << m-i << endl;
    }
    if(m%2)
    {
        for(int i=0;i<n/2;i++)
            cout << i+1 << ' ' << m/2+1 << endl << n-i << ' ' << m/2+1 << endl;
        if(n%2)
            cout << n/2+1 << ' ' << m/2+1;
    }
}