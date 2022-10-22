#include <bits/stdc++.h>
#define int long long
#define y1 iowfhjeofie
#define id long double

using namespace std;

int n, k;
char c[5][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i=0;i<4;i++)
        for(int j=0;j<n;j++)
        c[i][j]='.';
    if(k%2)
    {
        c[1][n/2]='#';
        k--;
    }

    for(int i=1;(k>0 && i<n/2);i++)
    {
        k-=2;
        c[1][i]='#';
        c[1][n-1-i]='#';
    }

    for(int i=1;(k>0 && i<n/2);i++)
    {
        k-=2;
        c[2][i]='#';
        c[2][n-1-i]='#';
    }

    if(k)
    {
        c[1][n/2]='#';
        c[2][n/2]='#';
    }

    cout << "YES\n";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<n;j++)
            cout << c[i][j];
        cout << "\n";
    }
}