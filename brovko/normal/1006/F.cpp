#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, a[20][20], k, ans;
map <int, int> q[20];

void rec(int i, int j, int x)
{
    if(i+j==n-1)
        {
            q[i][x]++;
            return;
        }
    if(i<n-1)
        rec(i+1, j, (x^a[i+1][j]));
    if(j<m-1 && j<n-1)
        rec(i, j+1, x^a[i][j+1]);
}

void rec2(int i, int j, int x)
{
    if(i+j==n)
    {
        ans+=q[i][x^k];
        if(i)
            ans+=q[i-1][x^k];
        return;
    }
    if(i>0)
        rec2(i-1, j, x^a[i-1][j]);
    if(j>0)
        rec2(i, j-1, x^a[i][j-1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    rec(0, 0, a[0][0]);
    if(m==1)
    {
        cout << q[n-1][k];
        return 0;
    }
    rec2(n-1, m-1, a[n-1][m-1]);
    cout << ans;
}