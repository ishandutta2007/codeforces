#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[10][10], b[10], c[10][10], x, y;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        x--;
        y--;
        a[x][y]++;
        a[y][x]++;
    }

    int Max=0;

    for(b[1]=0;b[1]<6;b[1]++)
        for(b[2]=0;b[2]<6;b[2]++)
        for(b[3]=0;b[3]<6;b[3]++)
        for(b[4]=0;b[4]<6;b[4]++)
        for(b[5]=0;b[5]<6;b[5]++)
        for(b[6]=0;b[6]<6;b[6]++)
    {
        for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
        c[i][j]=0;

        x=0;

        for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
        if(a[i][j])
        {
            c[b[i]][b[j]]=1;
        }

        for(int i=0;i<6;i++)
            for(int j=0;j<=i;j++)
            x+=c[i][j];

        Max=max(Max, x);
    }
    cout << Max;
}