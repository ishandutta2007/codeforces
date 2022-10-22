#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
char a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    int ans=0;
    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
            if(a[i][j]=='X' && a[i+1][j+1]=='X' && a[i+1][j-1]=='X' && a[i-1][j+1]=='X' && a[i-1][j-1]=='X')
            ans++;
    cout << ans;
}