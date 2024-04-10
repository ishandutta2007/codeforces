#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int a, b;

    cout << "? ";
    for(int i = 0; i < n; i++)
        cout << 0;

    cout << endl;
    cin >> a;

    cout << "? 1";
    for(int i = 0; i < n - 1; i++)
        cout << 0;

    cout << endl;
    cin >> b;

    if(a > b)
    {
        int L = 0;
        int R = n;
        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? ";
            for(int i = 0; i < M; i++)
                cout << 1;

            for(int i = M; i < n; i++)
                    cout << 0;

            cout << endl;

            int c;
            cin >> c;

            if(a - c == M)
                L = M;
            else R = M;
        }

        cout << "! " << R << ' ' << 1 << endl;
    }
    else
    {
        int L = 0;
        int R = n;
        while(R - L > 1)
        {
            int M = (L + R) / 2;

            cout << "? ";
            for(int i = 0; i < M; i++)
                cout << 1;

            for(int i = M; i < n; i++)
                    cout << 0;

            cout << endl;

            int c;
            cin >> c;

            if(a - c == -M)
                L = M;
            else R = M;
        }

        cout << "! " << 1 << ' ' << R << endl;
    }
}