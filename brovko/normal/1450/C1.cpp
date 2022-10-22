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

        int k[] = {0, 0, 0};

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] != '.')
                    k[(i + j) % 3]++;
            }

        int Min = 0;

        for(int i = 0; i < 3; i++)
            if(k[i] < k[Min])
                Min = i;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                if(a[i][j] != '.' && (i + j) % 3 == Min)
                    a[i][j] = 'O';
            }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j];

            cout << "\n";
        }
    }
}