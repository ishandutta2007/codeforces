#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << "First" << endl;

    int x = 1;
    int f = 0;

    while(x)
    {
        int A = a;
        int B = b;
        int C = c;

        if(A > B)
            swap(A, B);

        if(B > C)
            swap(B, C);

        if(A > B)
            swap(A, B);

        if(f == 1 && B - A == C - B)
        {
            cout << B - A << endl;
            cin >> x;
        }
        else
        {
            cout << 2 * C - A - B << endl;

            cin >> x;

            if(x == 1)
            {
                a += 2 * C - A - B;

                if(a > b && a > c)
                    f = 1;
            }

            if(x == 2)
            {
                b += 2 * C - A - B;

                if(a < b && b > c)
                    f = 1;
            }

            if(x == 3)
            {
                c += 2 * C - A - B;

                if(c > b && a < c)
                    f = 1;
            }
        }
    }
}