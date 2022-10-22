#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[2055], b, c;

vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mt19937 rnd(time(NULL));

    cin >> n;

    for(int i = 0; i < n; i++)
        a[i] = -1;

    int f = 0;

    while(f == 0)
    {
        int x = rnd() % n;
        v.push_back(x);

        int p = 2047;
        
        int k = 7;
        if(v.size() < 40)
            k = 12;
        if(v.size() < 20)
            k = 17;

        for(int i = 0; i < k; i++)
        {
            int y = x;
            while(y == x)
                y = rnd() % n;

            cout << "? " << x + 1 << ' ' << y + 1 << endl;

            int z;
            cin >> z;

            p &= z;
        }

        a[x] = p;

        for(auto to:v)
            if((p & a[to]) == 0)
        {
            b = x;
            c = to;
            f = 1;
        }
    }
    
    int F = 0;

    for(int i = 0; i < n; i++)
        if(a[i] == -1)
    {
        int z = 2047;

        cout << "? " << i + 1 << ' ' << b + 1 << endl;
        int p;
        cin >> p;
        z &= p;
        
        if(F == 0)
        {
            cout << "? " << i + 1 << ' ' << c + 1 << endl;
            int p;
            cin >> p;
            z &= p;
        }
        
        a[i] = z;
        
        if(a[i] == 0)
        {
            F = 1;
            b = i;
        }
    }

    cout << "! ";
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}