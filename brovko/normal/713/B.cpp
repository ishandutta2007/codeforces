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

    int L = 0;
    int R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << 1 << ' ' << M << ' ' << n << endl;

        int k;
        cin >> k;

        if(k)
            R = M;
        else L = M;
    }

    int x1 = R;

    L = 0;
    R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << 1 << ' ' << M << ' ' << n << endl;

        int k;
        cin >> k;

        if(k == 2)
            R = M;
        else L = M;
    }

    int x2 = R;

    L = 0;
    R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << 1 << ' ' << n << ' ' << M << endl;

        int k;
        cin >> k;

        if(k)
            R = M;
        else L = M;
    }

    int y1 = R;

    L = 0;
    R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << 1 << ' ' << n << ' ' << M << endl;

        int k;
        cin >> k;

        if(k == 2)
            R = M;
        else L = M;
    }

    int y2 = R;

    cout << "? " << 1 << ' ' << 1 << ' ' << x1 << ' ' << y1 << endl;

    int k;
    cin >> k;

    if(k == 0)
        swap(y1, y2);


    L = 1;
    R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << M << ' ' << 1 << ' ' << n << ' ' << n << endl;

        int k;
        cin >> k;

        if(k)
            L = M;
        else R = M;
    }

    int x3 = L;

    L = 1;
    R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << M << ' ' << 1 << ' ' << n << ' ' << n << endl;

        int k;
        cin >> k;

        if(k == 2)
            L = M;
        else R = M;
    }

    int x4 = L;

    L = 1;
    R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << M << ' ' << n << ' ' << n << endl;

        int k;
        cin >> k;

        if(k)
            L = M;
        else R = M;
    }

    int y3 = L;

    L = 1;
    R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        cout << "? " << 1 << ' ' << M << ' ' << n << ' ' << n << endl;

        int k;
        cin >> k;

        if(k == 2)
            L = M;
        else R = M;
    }

    int y4 = L;

    cout << "? " << x3 << ' ' << y3 << ' ' << n << ' ' << n << endl;

    cin >> k;

    if(k == 0)
        swap(y3, y4);

    int f = 1;

    if(x3 <= x1 && y3 <= y1)
    {
        cout << "? " << x3 << ' ' << y3 << ' ' << x1 << ' ' << y1 << endl;

        cin >> k;
        f *= k;
    }
    else f = 0;


    if(x4 <= x2 && y4 <= y2)
    {
        cout << "? " << x4 << ' ' << y4 << ' ' << x2 << ' ' << y2 << endl;

        cin >> k;
        f *= k;
    }
    else f = 0;

    if(f == 1)
        cout << "! " << x3 << ' ' << y3 << ' ' << x1 << ' ' << y1 << ' ' << x4 << ' ' << y4 << ' ' << x2 << ' ' << y2 << endl;
    else cout << "! " << x4 << ' ' << y4 << ' ' << x1 << ' ' << y1 << ' ' << x3 << ' ' << y3 << ' ' << x2 << ' ' << y2 << endl;
}