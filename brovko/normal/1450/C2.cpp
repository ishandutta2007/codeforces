#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n;
char a[305][305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }

        int k[] = {0, 0, 0, 0, 0, 0};

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] == 'O' && (i + j) % 3 == 0)
                {
                    k[0]++;
                    k[2]++;
                }

                if(a[i][j] == 'X' && (i + j) % 3 == 0)
                {
                    k[1]++;
                    k[3]++;
                }

                if(a[i][j] == 'O' && (i + j) % 3 == 1)
                {
                    k[1]++;
                    k[4]++;
                }

                if(a[i][j] == 'X' && (i + j) % 3 == 1)
                {
                    k[0]++;
                    k[5]++;
                }

                if(a[i][j] == 'O' && (i + j) % 3 == 2)
                {
                    k[3]++;
                    k[5]++;
                }

                if(a[i][j] == 'X' && (i + j) % 3 == 2)
                {
                    k[2]++;
                    k[4]++;
                }
            }

        int Min = 0;

        for(int i = 0; i < 6; i++)
            if(k[i] < k[Min])
                Min = i;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(Min == 0)
                {
                    if((i + j) % 3 == 0 && a[i][j] == 'O')
                        a[i][j] = 'X';

                    if((i + j) % 3 == 1 && a[i][j] == 'X')
                        a[i][j] = 'O';
                }

                if(Min == 1)
                {
                    if((i + j) % 3 == 0 && a[i][j] == 'X')
                        a[i][j] = 'O';

                    if((i + j) % 3 == 1 && a[i][j] == 'O')
                        a[i][j] = 'X';
                }

                if(Min == 2)
                {
                    if((i + j) % 3 == 0 && a[i][j] == 'O')
                        a[i][j] = 'X';

                    if((i + j) % 3 == 2 && a[i][j] == 'X')
                        a[i][j] = 'O';
                }

                if(Min == 3)
                {
                    if((i + j) % 3 == 0 && a[i][j] == 'X')
                        a[i][j] = 'O';

                    if((i + j) % 3 == 2 && a[i][j] == 'O')
                        a[i][j] = 'X';
                }

                if(Min == 4)
                {
                    if((i + j) % 3 == 1 && a[i][j] == 'O')
                        a[i][j] = 'X';

                    if((i + j) % 3 == 2 && a[i][j] == 'X')
                        a[i][j] = 'O';
                }

                if(Min == 5)
                {
                    if((i + j) % 3 == 1 && a[i][j] == 'X')
                        a[i][j] = 'O';

                    if((i + j) % 3 == 2 && a[i][j] == 'O')
                        a[i][j] = 'X';
                }
            }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j];

            cout << "\n";
        }
    }
}