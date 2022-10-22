#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n, a[1005][1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    int x=a[0][1];
    int y=a[1][2];
    int z=a[0][2];
    int b=round(sqrt(x*y/z));

    for(int i=0;i<n;i++)
        if(i==1)
            cout << b << ' ';
        else cout << a[1][i]/b << ' ';
}