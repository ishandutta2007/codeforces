#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

char c[10][10];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 100, b = 100;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> c[i][j];

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
        {
            if(c[i][j] == 'W')
            {
                int k = 0;

                for(int x = 0; x < i; x++)
                {
                    k++;

                    if(c[x][j] == 'B')
                        k += 100;
                }

                a = min(a, k);
            }

            if(c[i][j] == 'B')
            {
                int k = 0;

                for(int x = i + 1; x < 8; x++)
                {
                    k++;

                    if(c[x][j] == 'W')
                        k += 100;
                }

                b = min(b, k);
            }
        }

//    cout << a << ' ' << b << endl;

    if(a <= b)
        cout << "A";
    else cout << "B";
}