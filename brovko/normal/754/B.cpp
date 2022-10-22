#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

char a[4][4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> a[i][j];

    int f = 0;

    for(int i = 2; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            if(a[i][j] == '.' && a[i - 1][j] == 'x' && a[i - 2][j] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i - 1][j] == '.' && a[i - 2][j] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i - 1][j] == 'x' && a[i - 2][j] == '.')
                f = 1;
        }

    for(int i = 0; i < 4; i++)
        for(int j = 2; j < 4; j++)
        {
            if(a[i][j] == '.' && a[i][j - 1] == 'x' && a[i][j - 2] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i][j - 1] == '.' && a[i][j - 2] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i][j - 1] == 'x' && a[i][j - 2] == '.')
                f = 1;
        }

    for(int i = 2; i < 4; i++)
        for(int j = 2; j < 4; j++)
        {
            if(a[i][j] == '.' && a[i - 1][j - 1] == 'x' && a[i - 2][j - 2] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i - 1][j - 1] == '.' && a[i - 2][j - 2] == 'x')
                f = 1;

            if(a[i][j] == 'x' && a[i - 1][j - 1] == 'x' && a[i - 2][j - 2] == '.')
                f = 1;
        }

    for(int i = 2; i < 4; i++)
        for(int j = 2; j < 4; j++)
        {
            if(a[i][j - 2] == '.' && a[i - 1][j - 1] == 'x' && a[i - 2][j] == 'x')
                f = 1;

            if(a[i][j - 2] == 'x' && a[i - 1][j - 1] == '.' && a[i - 2][j] == 'x')
                f = 1;

            if(a[i][j - 2] == 'x' && a[i - 1][j - 1] == 'x' && a[i - 2][j] == '.')
                f = 1;
        }

    if(f)
        cout << "YES";
    else cout << "NO";
}