#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[1005], np[2000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i * i < 2000005; i++)
        if(np[i] == 0)
    {
        for(int j = i * i; j < 2000005; j += i)
            np[j] = 1;
    }

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int k1 = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 1)
            k1++;
    }

    int x = -1;
    
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 1 && np[a[i] + 1] == 0)
            x = a[i];
    }
    
    if(k1 + (int)(x != -1) > 1)
    {
        cout << k1 + (int)(x != -1) << "\n";
        
        while(k1--)
            cout << "1 ";
        
        if(x != -1)
            cout << x;
        
        return 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
    {
        if(np[a[i] + a[j]] == 0)
        {
            cout << "2\n" << a[i] << ' ' << a[j];
            return 0;
        }
    }

    cout << "1\n" << a[0];
}